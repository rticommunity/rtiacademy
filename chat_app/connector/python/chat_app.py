###############################################################################
# (c) 2021-2021 Copyright, Real-Time Innovations.  All rights reserved.       #
# No duplications, whole or partial, manual or electronic, may be made        #
# without express written permission.  Any such copies, or revisions thereof, #
# must display this notice unaltered.                                         #
# This code contains trade secrets of Real-Time Innovations, Inc.             #
###############################################################################

import os
import argparse
from posixpath import split
import threading

from time import sleep

from os import error, path as os_path

file_path = os_path.dirname(os_path.realpath(__file__))

parser = argparse.ArgumentParser(description='DDS Chat Application')

parser.add_argument('user', help='User Name')
parser.add_argument('group', help='Group Name')
parser.add_argument('firstname', help='First Name')
parser.add_argument('lastname', help='Last Name')

args = parser.parse_args()

os.environ['user'] = str(args.user)
os.environ['group'] = str(args.group)

import rticonnextdds_connector as rti

lock = threading.RLock()
finish_thread = False

def user_subscriber_task(user_input):
    global finish_thread

    while finish_thread == False:
        try:
            user_input.wait(500)
        except rti.TimeoutError as error:
            continue

        with lock:
            user_input.read()

            for sample in user_input.samples:
                if (sample.info['sample_state'] == "NOT_READ") and (sample.valid_data == False):
                    if (sample.info['instance_state'] == "NOT_ALIVE_NO_WRITERS"):
                        data = sample.get_dictionary()
                        print("#Gone user: " + data['username'])

def message_subscriber_task(message_input):
    global finish_thread

    while finish_thread == False:
        try:
            message_input.wait(500)
        except rti.TimeoutError as error:
            continue

        with lock:
            message_input.take()
            for sample in message_input.samples.valid_data_iter:
                data = sample.get_dictionary()
                print("#New message from: " + data['fromUser'] + ". Messsage: '" + data['message'] + "'")


def command_task(user, message_output, user_input):
    global finish_thread

    while finish_thread == False:
        value = input("Please enter command:\n")

        if value == "exit":
            finish_thread = True
        elif value == "list":
            with lock:
                user_input.read()

                for sample in user_input.samples.valid_data_iter:
                    if sample.info['instance_state'] == 'ALIVE':
                        data = sample.get_dictionary()
                        print("#user/group:" + data['username'] + "/" + data['group'])
        else:
            command = value.split(maxsplit=1)
            if len(command):
                if command[0] == "send":
                    with lock:
                        destination = command[1].split(maxsplit=1)

                        message_output.instance.set_string("fromUser", user)
                        message_output.instance.set_string("toUser", destination[0])
                        message_output.instance.set_string("toGroup", destination[0])
                        message_output.instance.set_string("message", destination[1])

                        message_output.write()
                else:
                    print("Wrong command\n")
            else:
                print("Wrong command\n")

with rti.open_connector(
    config_name="ChatParticipant_Library::ChatParticipant",
    url=file_path + "/chat_app.xml") as connector:

    user_output = connector.get_output("ChatUser_Publisher::ChatUser_DataWriter")
    message_output = connector.get_output("ChatMessage_Publisher::ChatMessage_DataWriter")

    user_input = connector.get_input("ChatUser_Subscriber::ChatUser_DataReader")
    message_input = connector.get_input("ChatMessage_Subscriber::ChatMessage_DataReader")
   
    #register instance
    user_output.instance.set_string("username", args.user)
    user_output.instance.set_string("group", args.group)
    user_output.instance.set_string("firstName", args.firstname)
    user_output.instance.set_string("lastName", args.lastname)

    user_output.write()

    #sleep(5)
    t1 = threading.Thread(target=command_task, args=(args.user, message_output, user_input))
    t1.start()

    t2 = threading.Thread(target=message_subscriber_task, args=(message_input, ))
    t2.start()

    t3 = threading.Thread(target=user_subscriber_task, args=(user_input, ))
    t3.start()

    t1.join()
    t2.join()
    t3.join()

    #unregister instance
    user_output.instance.set_string("username", args.user)

    user_output.write(action="unregister")
