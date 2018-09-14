#pragma once

class ServerIf
{
public:
    virtual void whoami() = 0;
    virtual int getServerId() = 0;
    virtual void handleMsg() = 0;   
 
    enum ServerIDs
    {
        ECHO_SERVER,
        TIME_SERVER
    };
};
