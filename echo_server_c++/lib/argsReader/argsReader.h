#pragma once

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#define false 0
#define true  1

class ArgsReader
{
public:
	ArgsReader();
	~ArgsReader();
	
	int read(int argc, char** argv);

    int getPort();
private:
    void handleHelp();
    void handleError();    


	int port;
    
};
