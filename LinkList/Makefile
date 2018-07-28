CC = gcc
CFLAGS = -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
OBJS = linklist.o main.o
linklist:${OBJS}
	${CC} $^ ${LDFLAGS} $@
linklist.o:linklist.c linklist.h
	${CC} ${CFLAGS} $<
main.o:main.c linklist.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf ${OBJS} $@
