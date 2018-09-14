#include "serverFactory.h"

shared_ptr<ServerIf> ServerFactory::createEchoServer()
{
    return shared_ptr<ServerIf>(new EchoServer);
}
