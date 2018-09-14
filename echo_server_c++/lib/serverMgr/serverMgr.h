#pragma once

#include <serverIf.h>
#include <vector>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

class ServerMgr
{
public:
    ServerMgr();
    ~ServerMgr();
    
    void addServer();
private:
    vetor<shared_ptr<ServerIf>> serverList;    
}

