#include <unp.h>
#include <serverFactory.h>
#include <serverMgr.h>

int
main(int argc, char **argv)
{
    ServerMgr serverMgr;
    if(!serverMgr.init(argc, argv))
    {
        return 0;
    }

    serverMgr.addServer(ServerFactory::createEchoServer());
    serverMgr.addServer(ServerFactory::createTimeServer());
    serverMgr.activeAllServer();

    serverMgr.start();
}
