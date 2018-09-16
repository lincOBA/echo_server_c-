#include "serverMgr.h"

ServerMgr::ServerMgr():
    listenfd(-1)
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

void ServerMgr::sig_chld(int signo)
{
    pid_t pid;
    int stat;
    while(( pid = waitpid(-1, &stat, WNOHANG) ) > 0)
        printf("child %d terminated\n", pid);
    return;
}

void ServerMgr::str_echo(int sockfd)
{
    ssize_t     n;
    char        buf[MAXLINE];

again:
    while ( (n = read(sockfd, buf, MAXLINE)) > 0)
        writen(sockfd, buf, n);

    if (n < 0 && errno == EINTR)
        goto again;
    else if (n < 0)
        err_sys("str_echo: read error");
}

void ServerMgr::err_sys(const char *fmt)
{
    printf(fmt);
    exit(0);
}

size_t ServerMgr::writen(int fd, const void *vptr, size_t n)
{
    size_t      nleft;
    ssize_t     nwritten;
    const char  *ptr;

    ptr = (const char*) vptr;
    nleft = n;
    while (nleft > 0) {
        if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
            if (nwritten < 0 && errno == EINTR)
                nwritten = 0;       /* and call write() again */
            else
                return(-1);         /* error */
        }

        nleft -= nwritten;
        ptr   += nwritten;
    }
    return(n);
}

void ServerMgr::init(int argc, char** argv)
{
    struct sockaddr_in  servaddr;
    void    sig_chld(int);

    listenfd = socket (AF_INET, SOCK_STREAM, 0); 

    bzero (&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

    listen(listenfd, LISTENQ);

    signal (SIGCHLD, ServerMgr::sig_chld); /* must call waitpid() */

}

void ServerMgr::start()
{
    int connfd;
    socklen_t clilen;
    pid_t   childpid;
    struct sockaddr_in cliaddr;
    for ( ; ; ) { 
        clilen = sizeof(cliaddr);
        if ( (connfd = accept (listenfd, (SA *) &cliaddr, &clilen)) < 0) {
            if (errno == EINTR)
                continue;          /* back to for() */
            else
                err_sys("accept error");
        }   

        if ( (childpid = fork()) == 0) { /* child process */
            close(listenfd);    /* close listening socket */
            str_echo(connfd);   /* process the request */
            exit(0);
        }   
        close (connfd);         /* parent closes connected socket */
    }    
}
