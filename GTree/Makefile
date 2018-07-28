CC = gcc
CFLAGS = -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
OBJS = GTree.o LinkList.o main.o
GTree:${OBJS}
	${CC} $^ ${LDFLAGS} $@
GTree.o:GTree.c GTree.h
	${CC} ${CFLAGS} $<
LinkList.o:LinkList.c LinkList.h
	${CC} ${CFLAGS} $<
main.o:main.c GTree.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf GTree *.o
