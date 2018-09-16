#include <unp.h>
#include <serverFactory.h>
#include <serverMgr.h>

int
main(int argc, char **argv)
{
    ServerMgr serverMgr;
    serverMgr.addServer(ServerFactory::createEchoServer());
    serverMgr.addServer(ServerFactory::createTimeServer());
    serverMgr.activeAllServer();

    serverMgr.init(argc, argv);
    serverMgr.start();
}
