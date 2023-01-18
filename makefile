CFLAGS = -g -Wall
CC = gcc
OBJS = algo.o nodes.o edges.o

all: graph functions

graph: main.o libFuncs.so
	$(CC) $(CFLAGS) -o graph main.o -L. -lFuncs

functions: libFuncs.so

libFuncs.so: $(OBJS)
	$(CC) -shared -fPIC -o libFuncs.so $(OBJS)

main.o: main.c algo.h nodes.h edges.h
	$(CC) $(CFLAGS) -c main.c

algo.o: algo.c algo.h nodes.h edges.h
	$(CC) $(CFLAGS) -c algo.c

nodes.o: nodes.c algo.h nodes.h edges.h
	$(CC) $(CFLAGS) -c nodes.c

edges.o: edges.c algo.h nodes.h edges.h
	$(CC) $(CFLAGS) -c edges.c

.PHONY: all clean graph functions

clean:	
	rm -f *.o *.so main graph

