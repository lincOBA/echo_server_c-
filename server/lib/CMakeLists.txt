#lib/CMakeLists.txt
cmake_minimum_required(VERSION 2.6)
add_subdirectory(serverFactory)
add_subdirectory(serverMgr)
add_subdirectory(argsReader)
add_library(Lib STATIC
writen.cpp
)
target_link_libraries(Lib 
ServerFactory
ServerMgr
ArgsReader
)

