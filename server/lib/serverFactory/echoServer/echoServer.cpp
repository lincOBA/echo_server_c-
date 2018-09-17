#include "echoServer.h"
#include <stdio.h>

void EchoServer::whoami()
{ 
    printf("I'm echo server \n");
}

int EchoServer::getServerId()
{
    return serverId;
}

void EchoServer::handleMsg()
{
    whoami();
}
