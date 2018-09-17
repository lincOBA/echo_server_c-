#include "timeServer.h"
#include <stdio.h>

void TimeServer::whoami()
{ 
    printf("I'm time server \n");
}

int TimeServer::getServerId()
{
    return serverId;
}

void TimeServer::handleMsg()
{
    whoami();
}
