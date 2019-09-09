#include "echoserver.h"
#include <sys/types.h>

int setPort (int argc, char **argv){
	if (argc == 1 || atoi(argv[1])>55000 || atoi(argv[1])<50000)
        return 50000;
    else
    {
        return atoi(argv[1]);
    }
}



int serverConnect (int listener, int PORT){
    
    struct sockaddr_in myaddr;
	listener = socket(PF_INET, SOCK_STREAM, 0);
	criticalErrors("socket", listener);
	
	myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = INADDR_ANY;
    myaddr.sin_port = htons(PORT);
    memset(&(myaddr.sin_zero), '\0', 8);
	
	while (bind(listener, (struct sockaddr *)&myaddr, sizeof(myaddr)) == -1 && PORT<=55000)
    {
        PORT++;
        myaddr.sin_port = htons(PORT);
    }
	
	if (PORT==55001)
    {
        perror("bind failed. PORT not finded");
        exit(1);
    }
	
	printf("Server started. IP: %s PORT %d\n", inet_ntoa(myaddr.sin_addr), PORT);
    return listener;
}
