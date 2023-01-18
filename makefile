CFLAGS = -g -Wall
CC = gcc
OBJS = algo.o nodes.o edges.o
LIBS = algo.h nodes.h edges.h

all: graph functions

graph: main.o libFuncs.so
	$(CC) $(CFLAGS) -o graph main.o -L. -lFuncs

functions: libFuncs.so

libFuncs.so: $(OBJS)
	$(CC) -shared -fPIC -o libFuncs.so $(OBJS)

main.o: main.c $(LIBS)
	$(CC) $(CFLAGS) -c main.c

algo.o: algo.c $(LIBS)
	$(CC) $(CFLAGS) -c algo.c

nodes.o: nodes.c $(LIBS)
	$(CC) $(CFLAGS) -c nodes.c

edges.o: edges.c $(LIBS)
	$(CC) $(CFLAGS) -c edges.c

.PHONY: all clean graph functions

clean:	
	rm -f *.o *.so main graph

