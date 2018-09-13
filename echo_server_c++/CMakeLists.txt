cmake_minimum_required (VERSION 2.6)
include_directories(inc)
add_subdirectory(lib)
add_executable(EchoServer 
src/main.cpp
src/error.cpp
src/sig.cpp
src/echo.cpp
)
target_link_libraries(EchoServer Lib) 
