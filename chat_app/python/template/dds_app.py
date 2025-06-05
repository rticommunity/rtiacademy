import rti.connextdds as dds

from chat import ChatUser, ChatMessage

import os
import threading
from typing import Callable, List
import logging



class Handlers:
    users_joined: Callable[[List[ChatUser]], None] = lambda *_: logging.warning("Not implemented")
    users_dropped: Callable[[List[ChatUser]], None] = lambda *_: logging.warning("Not implemented")
    message_received: Callable[[List[ChatMessage]], None] = lambda *_: logging.warning("Not implemented")



class DDSApp:
    """DDS application for chat messaging, to be driven from the application code."""

    def __init__(self, user : ChatUser, handlers=Handlers(), auto_join=True, domain_id=0):
        pass

    def user_join(self):
        pass    

    def user_update_group(self, group):
        pass

    def user_list(self):
        pass

    def message_send(self, destination, message):
        pass

    def user_leave(self):
        pass