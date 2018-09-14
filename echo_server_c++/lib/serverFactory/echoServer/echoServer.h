#pragma once
#include <unp.h>
#include <serverIf.h>

class EchoServer : public ServerIf
{
public:
    EchoServer(){};
    ~EchoServer(){};
    virtual void whoami();
    virtual int getServerId();
    virtual void handleMsg();

    static const int serverId = ECHO_SERVER;
};

