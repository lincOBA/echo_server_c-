#include <unp.h>
#include <serverFactory.h>
#include <serverMgr.h>

int
main(int argc, char **argv)
{
    ServerMgr serverMgr;
    serverMgr.init(argc, argv);

    serverMgr.addServer(ServerFactory::createEchoServer());
    serverMgr.addServer(ServerFactory::createTimeServer());
    serverMgr.activeAllServer();

    serverMgr.start();
}
