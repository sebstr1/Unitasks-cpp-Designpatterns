cmake_minimum_required(VERSION 3.2)
project(server)

set(CMAKE_CXX_STANDARD 11)

include_directories($ENV{TOOLS_INCLUDE} ${CMAKE_SOURCE_DIR}/include)

#include(ExternalData)

set(CMAKE_SUPPRESS_REGENERATION true)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#set(ExternalData_URL_TEMPLATES
#    "file://src/skafferi.dat"
#)

# Om Debug mode
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Skriv ut meddelandet Debug mode
    message("Debug mode")
    add_definitions(-DDEBUG)
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Skriv ut meddelandet Release mode.
    message("Release mode")
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")


set(SRC_LIST
        Address.h
        ChatLogger.h ChatLogger.cpp
        ChatObserver.h
        ChatServer.cpp
        ClientConnection.h ClientConnection.cpp
        ClientListener.h ClientListener.cpp
        ClientProxy.h 
        Connection.h
        Message.h Message.cpp
        Server.h
)

add_executable(${PROJECT_NAME} ${SRC_LIST})




