CC = gcc
CFLAGS = -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
OBJS = linklist.o linkqueue.o main.o
linkqueue:${OBJS}
	${CC} $^ ${LDFLAGS} $@
linkqueue.o:linkqueue.c linkqueue.h
	${CC} ${CFLAGS} $<
linklist.o:linklist.c linklist.h
	${CC} ${CFLAGS} $<
main.o:main.c linkqueue.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf ${OBJS} $@
