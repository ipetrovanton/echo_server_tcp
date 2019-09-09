#include "echoserver.h"
#include <sys/types.h>
int main (int argc, char **argv)
{
    int listener = 0;                   // дескриптор слушающего сокета
    int PORT;
 
	PORT=setPort(argc, argv);
	listener = serverConnect (listener, PORT);
    
	mainLoop(listener);
	return 0;
}
