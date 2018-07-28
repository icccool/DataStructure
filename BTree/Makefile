CC = gcc
CFLAGS = -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
OBJS = BTree.o linkqueue.o linklist.o main.o 
BTree:${OBJS}
	${CC} $^ ${LDFLAGS} $@
linklist.o:linklist.c linklist.h
	${CC} ${CFLAGS} $<
linkqueue.o:linkqueue.c linkqueue.h
	${CC} ${CFLAGS} $<
BTree.o:BTree.c BTree.h
	${CC} ${CFLAGS} $<
main.o:main.c BTree.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf BTree *.o
