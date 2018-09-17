#pragma once

#include <serverIf.h>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <unp.h>

using namespace std;
using namespace boost;

class ServerMgr
{
public:
    ServerMgr();
    ~ServerMgr();
    
    int init(int argc, char* argv[]);
    void start();
    
    void addServer( shared_ptr<ServerIf> server);
    void activeAllServer();

private:

    static void sig_chld(int signo);
    void str_echo(int sockfd);
    void err_sys(const char *fmt);
    size_t writen(int fd, const void *vptr, size_t n);

    vector< shared_ptr<ServerIf> > serverList;    
    int     listenfd;
};

