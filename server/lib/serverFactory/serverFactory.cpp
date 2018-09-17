#include "serverFactory.h"

shared_ptr<ServerIf> ServerFactory::createEchoServer()
{
    return shared_ptr<ServerIf>(new EchoServer);
}

shared_ptr<ServerIf> ServerFactory::createTimeServer()
{
    return shared_ptr<ServerIf>(new TimeServer);
}

