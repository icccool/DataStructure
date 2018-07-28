CC = gcc
CFLAGS = -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
OBJS = linklist.o linkstack.o match.o
match:${OBJS}
	${CC} $^ ${LDFLAGS} $@
linklist.o:linklist.c linklist.h
	${CC} ${CFLAGS} $<
linkstack.o:linkstack.c linkstack.h
	${CC} ${CFLAGS} $<
match.o:match.c linkstack.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf ${OBJS} $@
