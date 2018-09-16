cmake_minimum_required (VERSION 2.6)
include_directories(inc)
add_subdirectory(lib)
add_executable(Server 
src/main.cpp
)
target_link_libraries(Server ServerFactory Lib) 
