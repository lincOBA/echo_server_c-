#lib/CMakeLists.txt
cmake_minimum_required(VERSION 2.6)
add_subdirectory(echoServer)
add_subdirectory(timeServer)
add_library(ServerFactory STATIC
serverFactory.cpp
)
target_link_libraries(ServerFactory 
EchoServer
TimeServer
)
