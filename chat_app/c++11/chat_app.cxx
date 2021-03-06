
/*
 * (c) 2021 Copyright, Real-Time Innovations, Inc. (RTI) All rights reserved.
 *
 * RTI grants Licensee a license to use, modify, compile, and create derivative
 * works of the Software solely in combination with RTI Connext DDS. Licensee
 * may redistribute copies of the Software provided that all such copies are
 * subject to this License. The Software is provided "as is", with no warranty
 * of any type, including any warranty for fitness for any purpose. RTI is
 * under no obligation to maintain or support the Software. RTI shall not be
 * liable for any incidental or consequential damages arising out of the use or
 * inability to use the Software. For purposes of clarity, nothing in this
 * License prevents Licensee from using alternate versions of DDS, provided
 * that Licensee may not combine or link such alternate versions of DDS with
 * the Software.
 */

#include <iostream>
#include <string>
#include <thread>
using namespace std;

#include <dds/dds.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/util/util.hpp>
#include "chat.hpp"

using namespace dds::domain;
using namespace dds::topic;
using namespace dds::pub;
using namespace dds::sub;
using namespace dds::sub::status;
using namespace dds::sub::cond;
using namespace dds::core::cond;
using namespace dds::pub::qos;
using namespace dds::sub::qos;
using namespace dds::core::policy;

dds::core::cond::GuardCondition stop_condition;


int publisher_message(string& username, DataWriter<ChatMessage>& message_writer,
        DataReader<ChatUser>& user_reader)
{
    while (true) {
        string input, command;
        getline(cin, input);
        stringstream ss(input);
        getline(ss, command, ' ');

        if (command == "send") {
            // send username text text text
            ChatMessage instance;
            string destination;
            string message;

            getline(ss, destination, ' ');
            getline(ss, message, '\n');

            instance.fromUser(username);
            instance.toUser(destination);
            instance.toGroup(destination);
            instance.message(message);

            // write
            message_writer.write(instance);

        }
        else if (command == "list") {
            
            LoanedSamples<ChatUser> samples = user_reader.read();
            for (auto sampleIt = samples.begin(); sampleIt != samples.end(); sampleIt++) {
                if (sampleIt->info().valid()) {
                    if (sampleIt->info().state().instance_state() == InstanceState::alive()) {
                        cout << "# " << sampleIt->data().username() << " " << sampleIt->data().group() << endl;
                    }
                }
            }
        } else if (command == "exit") {

            stop_condition.trigger_value(true);
            break;

        } else {
            cout << "___Unsupported command" << endl;
        }
    }

    return 0;
}

int subscriber_message(DataReader<ChatMessage>& message_reader)
{
    ReadCondition read_condition(message_reader, DataState::any());
    WaitSet waitset;
    waitset.attach_condition(read_condition);
    waitset.attach_condition(stop_condition);

    while (true) {
        WaitSet::ConditionSeq active_conditions = waitset.wait(dds::core::Duration(60));
        if (active_conditions.size() == 0) {
            cout << "Timeout; no conditions were triggered\n";
            continue;
        }

        for (int c = 0; c < active_conditions.size(); c++) {
            if (active_conditions[c] == read_condition) {
                LoanedSamples<ChatMessage> samples = message_reader.take();
                for (auto sampleIt = samples.begin(); sampleIt != samples.end(); sampleIt++) {
                    if (sampleIt->info().valid()) {
                        cout << sampleIt->data().fromUser() << ": " << sampleIt->data().message() << endl;
                    }
                }
            } else if (active_conditions[c] == stop_condition) {
                return 0;
            }
        }
    }
    return 0;
}

int publisher_userInfo(DataWriter<ChatUser>& user_writer, string& user, string& group,
        string& first, string& last)
{
    ChatUser instance;

    instance.username(user);
    instance.group(group);
    instance.firstName(first);
    instance.lastName(last);

    dds::core::InstanceHandle handle = user_writer.register_instance(instance);
    user_writer.write(instance);

    while (true) {
        rti::util::sleep(dds::core::Duration(5));
        if (stop_condition.trigger_value() == true) {
            user_writer.unregister_instance(handle);
            break;
        }
    }
    return 0;
}

int subscriber_userInfo(DataReader<ChatUser>& user_reader)
{
    ReadCondition read_condition(user_reader, DataState(SampleState::any(), ViewState::any(),
        InstanceState::not_alive_mask()));
    WaitSet waitset;
    waitset.attach_condition(read_condition);
    waitset.attach_condition(stop_condition);

    while (true) {
        WaitSet::ConditionSeq active_conditions = waitset.wait(dds::core::Duration(60));
        if (active_conditions.size() == 0) {
            cout << "Timeout; no conditions were triggered\n";
            continue;
        }

        for (int c = 0; c < active_conditions.size(); c++) {
            if (active_conditions[c] == read_condition) {
                LoanedSamples<ChatUser> samples = user_reader.select().condition(read_condition).take();
                for (auto sampleIt = samples.begin(); sampleIt != samples.end(); sampleIt++) {
                    if (sampleIt->info().valid()) {
                        if (sampleIt->info().state().instance_state() == InstanceState::not_alive_no_writers()) {
                            cout << sampleIt->data().username() << ": has been dropped\n";
                        }
                    }
                }
            }
            else if (active_conditions[c] == stop_condition) {
                return 0;
            }
        }
    }
    return 0;
}


int main(int argc, char* argv[])
{
    string username, group;
    string firstName, lastName;

    if (argc < 3) {
        cerr << "Usage: chat_app username group [firstName] [lastName]" << endl;
        return -1;
    }
    username = string(argv[1]);
    group = string(argv[2]);
    if (argc >= 4)
        firstName = string(argv[3]);
    if (argc >= 5)
        lastName = string(argv[4]);

    const int domain_id = 10;

    try {
        dds::core::QosProvider qos_provider("chat_qos.xml");
        DomainParticipant participant(domain_id, qos_provider->participant_qos("Chat_Library::Chat_Profile"));

        const string userInfo_topic_name = "userInfo";
        const string message_topic_name = "message";
        Topic<ChatUser> userInfo_topic(participant, userInfo_topic_name);
        Topic<ChatMessage> message_topic(participant, message_topic_name);

        DataWriter<ChatUser> user_writer(Publisher(participant), userInfo_topic,
            qos_provider->datawriter_qos("Chat_Library::ChatUser_Profile"));

        DataReader<ChatUser> user_reader(Subscriber(participant), userInfo_topic,
                qos_provider->datareader_qos("Chat_Library::ChatUser_Profile"));
        
        vector<string> partition_names = { group };

        PublisherQos publisher_qos = dds::core::QosProvider::Default().publisher_qos();
        Partition pub_partition = publisher_qos.policy<Partition>();
        pub_partition.name(partition_names);
        publisher_qos << pub_partition;
        Publisher message_publisher(participant, publisher_qos);

        DataWriter<ChatMessage> message_writer(message_publisher, message_topic,
                qos_provider->datawriter_qos("Chat_Library::ChatMessage_Profile"));

        // CFT
        vector<string> parameters = { "'" + username + "'", "'" + group + "'" };
        ContentFilteredTopic<ChatMessage> cft_message_topic(message_topic, "Message_CFT",
                Filter("toUser MATCH %0 or toGroup MATCH %1", parameters));
        
        SubscriberQos subscriber_qos = dds::core::QosProvider::Default().subscriber_qos();
        Partition sub_partition = subscriber_qos.policy<Partition>();
        sub_partition.name(partition_names);
        subscriber_qos << sub_partition;
        Subscriber message_subscriber(participant, subscriber_qos);

        DataReader<ChatMessage> message_reader(message_subscriber, cft_message_topic,
                qos_provider->datareader_qos("Chat_Library::ChatMessage_Profile"));


        // create threads
        thread subscriber_thread_userInfo(subscriber_userInfo, user_reader);
        thread subscriber_thread_message(subscriber_message, message_reader);
        thread publisher_thread_userInfo(publisher_userInfo, user_writer,
            username, group, firstName, lastName);
        publisher_message(username, message_writer, user_reader);

        // wait for threads to finish
        publisher_thread_userInfo.join();
        subscriber_thread_userInfo.join();
        subscriber_thread_message.join();

    } catch (const exception& ex) {
        cout << "Exception " << ex.what() << endl;
    }
    return 0;
}
