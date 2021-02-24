
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



int publisher_message()
{
    while (true) {
        string input, command;
        getline(cin, input);
        stringstream ss(input);
        getline(ss, command, ' ');

        if (command == "send") {
        
        } else {
            cout << "___Unsupported command" << endl;
        }
    }

    return 0;
}

int publisher_userInfo()
{
    return 0;
}

int subscriber_message()
{
    return 0;
}

int subscriber_userInfo()
{
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

        DataReader<ChatUser> user_reader(Subscriber(participant), userInfo_topic,
                qos_provider->datareader_qos("Chat_Library::ChatUser_Profile"));
        DataReader<ChatMessage> message_reader(Subscriber(participant), message_topic,
                qos_provider->datareader_qos("Chat_Library::ChatMessage_Profile"));

        DataWriter<ChatUser> user_writer(Publisher(participant), userInfo_topic,
                qos_provider->datawriter_qos("Chat_Library::ChatUser_Profile"));
        DataWriter<ChatMessage> message_writer(Publisher(participant), message_topic,
                qos_provider->datawriter_qos("Chat_Library::ChatMessage_Profile"));

        // create threads
        thread subscriber_thread_userInfo(subscriber_userInfo);
        thread subscriber_thread_message(subscriber_message);
        thread publisher_thread_userInfo(publisher_userInfo);
        publisher_message();

        // wait for threads to finish
        publisher_thread_userInfo.join();
        subscriber_thread_userInfo.join();
        subscriber_thread_message.join();

    } catch (const exception& ex) {
        cout << "Exception " << ex.what() << endl;
    }
    return 0;
}
