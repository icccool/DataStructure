CC = gcc
CFLAGS = -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
OBJS = linklist.o linkstack.o main.o
linkstack:${OBJS}
	${CC} $^ ${LDFLAGS} $@
linklist.o:linklist.c linklist.h
	${CC} ${CFLAGS} $<
linkstack.o:linkstack.c linkstack.h
	${CC} ${CFLAGS} $<
main.o:main.c linkstack.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf ${OBJS} $@
