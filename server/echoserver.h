#ifndef ECHOSERVER_H
#define ECHOSERVER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

void criticalErrors (char *, int);
void errors (char *, int);
int setPort (int argc, char **argv);
int serverConnect(int, int);
int bind(int, const struct sockaddr *, socklen_t) __DARWIN_ALIAS(bind);
void mainLoop(int);
#endif //ECHOSERVER_H
