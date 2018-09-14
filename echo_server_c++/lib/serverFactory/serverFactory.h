#pragma once

#include <serverIf.h>
#include <echoServer.h>
#include <boost/shared_ptr.hpp>

using namespace boost;

class ServerFactory
{
public:
    static shared_ptr<ServerIf> createEchoServer();

private:
    ServerFactory(){};
    ~ServerFactory(){};
};


