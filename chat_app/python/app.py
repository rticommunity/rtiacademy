import gui
import dds_app



class MainApp:
    """Main application, simple bridging between the the DDS chat application and the GUI."""

    def __init__(self):
        "Initialise the GUI and DDS application, and bind the handlers."
        
        # Initialise GUI and bindings
        self.gui_handlers = gui.Handlers()
        self.gui_handlers.join = self.join
        self.gui_handlers.update_user = self.update_user
        self.gui_handlers.leave = self.leave
        self.gui_handlers.list_users = self.list_users
        self.gui_handlers.send_message = self.send
        self.gui = gui.GuiApp(self.gui_handlers)
        
        # DDS App and bindings
        self.dds_user = None
        self.dds_handlers = dds_app.Handlers()
        self.dds_handlers.users_joined = self.joined
        self.dds_handlers.users_dropped = self.left
        self.dds_handlers.message_received = self.received
        self.dds_app = None

        # Start the GUI
        self.gui.start()

        # If the GUI is closed, clean-up
        self.leave()
    

    def join(self, user, group, name, last_name):
        """Join the chat with the provided details."""

        self.dds_user = dds_app.ChatUser(username=user, group=group, firstName=name, lastName=last_name)
        self.dds_app = dds_app.DDSApp(self.dds_user, self.dds_handlers)
    

    def update_user(self, group):
        """Update the user group."""

        # Early exit if not set up previously
        if not self.dds_app:
            return

        # Update the user group in the DDS application
        self.dds_app.user_update_group(group=group)
    

    def leave(self):
        """Leave the chat and clean up the DDS application."""

        # Early exit if not set up previously
        if not self.dds_app:
            return

        self.dds_app.user_leave()
    
    
    def list_users(self):
        """List all users in the chat."""

        # Early exit if not set up previously
        if not self.dds_app:
            return

        user_samples = self.dds_app.user_list()
        users = [[s.username, s.group, s.firstName, s.lastName] for s in user_samples]
        return users
    

    def joined(self, user_samples):
        """User joined the chat, update the GUI."""
        
        users = [[s.username, s.group, s.firstName, s.lastName] for s in user_samples]
        for user in users:
            self.gui.user_joined(*user)
    

    def left(self, user_samples):
        """User left the chat, update the GUI."""

        for user in user_samples:
            if user.username == self.dds_user.username:
                continue
            self.gui.user_left(user.username)
    

    def send(self, destination, message):
        """Send a message to the provided destination (user or group)."""

        # Early exit if not set up previously
        if not self.dds_app:
            return

        self.dds_app.message_send(destination=destination, message=message)
    

    def received(self, message_samples):
        """A message was received, update the GUI."""

        # Note toUser and toGroup have the same data
        messages = [[s.fromUser, s.toUser, s.message] for s in message_samples]
        for msg in messages:
            self.gui.message_received(*msg)



def test():
    app = MainApp()
    app.join("testuser", "services", "", "")
    return app


def main():
    app = MainApp()
    return app



if __name__ =="__main__":
    app = main()