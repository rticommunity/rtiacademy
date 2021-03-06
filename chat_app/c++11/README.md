# Chat App

In this directory you will find the code for the **_Writing a Connext DDS Chat Application_** course.

This is the C++ 11 example that builds the command-line chat application using Connext DDS. 

## Prerequisites

- Connext 6.0.0 or higher
- Windows 10
- Visual Studio 2015

## Build the example

This example contains the project files to make it work on Visual Studio 2015.

Before compiling the project, you have to run Code Generator to create the C++11 files from the idl (chat.idl).
You have to set the unbounded support flag.

```bash
rtiddsgen chat.idl -language C++11 -create typefiles -unboundedSupport
```

## How to use it

There are several tags, corresponding to each coding video:
*chat-app_video8* to *chat-app_video17*

You only have to checkout the required tag when watching the video.

## Building using CMake

There is a separate branch that allows building the last version of the code with
CMake: [chat-app_cmake](https://github.com/rticommunity/rtiacademy/tree/chat-app_cmake)
