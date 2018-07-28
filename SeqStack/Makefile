CC = gcc
CFLAGS = -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
OBJS = seqlist.o seqstack.o main.o
seqstack:${OBJS}
	${CC} $^ ${LDFLAGS} $@
seqstack.o:seqstack.c seqstack.h
	${CC} ${CFLAGS} $<
seqlist.o:seqlist.c seqlist.h
	${CC} ${CFLAGS} $<
main.o:main.c seqstack.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf ${OBJS} $@
