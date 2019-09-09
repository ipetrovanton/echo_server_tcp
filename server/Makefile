CC = gcc
FILES = main.c transport_layer.c main_loop.c error_handing.c
TARCGET = echoserver
CFLAGS = -c -Wall
OBJECTS = main.o transport_layer.o main_loop.o error_handing.o

all:	echoserver

echoserver:	$(OBJECTS)
	$(CC) -o echoserver $(OBJECTS)

$(OBJECTS):	$(FILES)
	$(CC) $(CFLAGS) $(FILES)

clean:
	rm -f $(OBJECTS) echoserver
