CC = gcc
CFLAGS = -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
OBJS = seqlist.o seqqueue.o main.o
seqqueue:${OBJS}
	${CC} $^ ${LDFLAGS} $@
seqqueue.o:seqqueue.c seqqueue.h
	${CC} ${CFLAGS} $<
seqlist.o:seqlist.c seqlist.h
	${CC} ${CFLAGS} $<
main.o:main.c seqqueue.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf ${OBJS} seqqueue
