#include <argsReader.h>
#include <stdlib.h>

ArgsReader::ArgsReader():
    port(8888)
{
}

ArgsReader::~ArgsReader()
{

}

int ArgsReader::getPort()
{
    return port;
}

void ArgsReader::handleHelp()
{
    char helpInfo[] = "----------------------------help info--------------------------------\n\n"
                      " usage: ./Server {\033[35;40m--port\033[0m PORT} \n"
                      " \033[35;40m--port\033[0m : using this port to listen client request. default it's 8888\n"
                      "\n---------------------------------------------------------------------"
                      "\n";
    printf("%s", helpInfo);

}

void ArgsReader::handleError()
{
    char errorInfo[] = "error: \033[1;4;34;40minvalid usage\033[0m\n"
                       "use \033[35;40m--help\033[0m for more information.\n";
    printf("%s", errorInfo); 

}


int ArgsReader::read(int argc, char** argv)
{
    int opt;
    int digit_optind = 0;
    int option_index = 0;
    char string[] = "";
    static struct option long_options[] =
    {
        {"readable",      no_argument,        NULL, 'r'},
        {"port",          required_argument,  NULL, 't'},
        {"help",          no_argument,        NULL, 'p'},
        {NULL,            0,                  NULL, 0}, 
    };  

    while((opt =getopt_long_only(argc,argv,string,long_options,&option_index))!= -1) 
    {   
        switch(opt)
        {   
        case 'r':
            printf("--readable\n");
            break;
        case 't':
            printf("--port %s\n", optarg);
            port = atoi(optarg);
            break;
        case 'p':
            handleHelp();
            return false;
        default:
            handleError();
            return false;
        }
    }

    return true;
}
