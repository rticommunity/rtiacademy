# Chat App

In this directory you will find the code for the **_Writing a Connext DDS Chat Application_** course.

This example builds a command-line chat application using Connext DDS. It defines the types, the
topics and the Quality of Service best suited for a scalable distributed application.

## Prerequisites

- Connext 6.0.1 or 6.1.0
- Windows 10
- Visual Studio 2015

## Build the example

This example contains the project files to make it work on Visual Studio 2015.

Before compiling the project, you have to run Code Generator to create the C++11 files from the idl (chat.idl). You have to set the unbounded support flag.

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
