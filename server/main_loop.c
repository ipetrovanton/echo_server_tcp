#include "echoserver.h"
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>

void mainLoop(int listener)
{
	fd_set master;               
    fd_set read_fds;
	struct sockaddr_in remoteaddr;
	int fdmax;	
    int newfd;
	int nbytes;
	char buf[1024];
    socklen_t addrlen;
	
	int error = listen(listener, 10);
	criticalErrors("listener", error);
   
	FD_ZERO(&master);
    FD_ZERO(&read_fds);
	FD_SET(listener, &master);
	
    fdmax = listener;
	for (;;)
        {
        read_fds = master;
		int errorSelect = select(fdmax + 1, &read_fds, NULL, NULL, NULL);
		criticalErrors("select", errorSelect);
      
        for (int i = 0; i <= fdmax; i++)
        {
            if (FD_ISSET(i, &read_fds))
            {
                if (i == listener)
                {
                    addrlen = sizeof(remoteaddr);
                    newfd = accept(listener, (struct sockaddr *)&remoteaddr,
                                        &addrlen);
					errors("accept", newfd);
                    if(newfd != -1)
                    {
                        FD_SET(newfd, &master); 
                        if (newfd > fdmax)
                        {
                            fdmax = newfd;
                        }
                        printf("myserver: новое соединение от %s на "
                               "сокете %d\n",
                               inet_ntoa(remoteaddr.sin_addr), newfd);
                    }
                }
                else
                {
                    if ((nbytes = recv(i, buf, sizeof(buf), 0)) <= 0)
                    {
                        if (nbytes == 0)
                        {
                            printf("myserver: сокет %d отключился\n", i);
                        }
                        else
							errors("recv", nbytes);
                        close(i);           
                        FD_CLR(i, &master);
                    }
                    else
                    {
                        send(i, buf, nbytes, 0);
                        printf("myserver: Клиенту %s на "
                               "сокете %d отправлено: %s\n",
                               inet_ntoa(remoteaddr.sin_addr), newfd, buf);
                    }
                }
            }
        }
        }
}
