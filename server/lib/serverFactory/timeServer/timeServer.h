#pragma once
#include <unp.h>
#include <serverIf.h>

class TimeServer : public ServerIf
{
public:
    TimeServer(){};
    ~TimeServer(){};
    virtual void whoami();
    virtual int getServerId();
    virtual void handleMsg();
    static const int serverId = TIME_SERVER;
};

