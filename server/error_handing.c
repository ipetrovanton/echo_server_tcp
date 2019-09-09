#include "echoserver.h"

void criticalErrors (char *message, int functionReturn){
	if(functionReturn < 0){
		perror(message);
		exit(1);
	}
}

void errors (char *message, int functionReturn){
	if(functionReturn < 0){
		perror(message);
	}
}



