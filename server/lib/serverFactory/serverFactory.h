#pragma once

#include <serverIf.h>
#include <echoServer.h>
#include <timeServer.h>
#undef max
#undef min
#include <boost/shared_ptr.hpp>

using namespace boost;

class ServerFactory
{
public:
    static shared_ptr<ServerIf> createEchoServer();
    static shared_ptr<ServerIf> createTimeServer();
private:
    ServerFactory(){};
    ~ServerFactory(){};
};


