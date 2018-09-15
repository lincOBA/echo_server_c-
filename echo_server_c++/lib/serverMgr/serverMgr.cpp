#include "serverMgr.h"

ServerMgr::ServerMgr()
{

}

ServerMgr::~ServerMgr()
{

}

void ServerMgr::addServer( shared_ptr<ServerIf> server)
{
    serverList.push_back(server);
}

void ServerMgr::activeAllServer()
{
    for(int i = 0 ; i < serverList.size(); i ++ )
    {
        serverList[i]->handleMsg();
    }

}
