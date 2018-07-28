OBJS = main.o staticlist.o
CFLAGS= -Wall -std=c99 -g 
CC = gcc
staticlist:${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}
main.o:main.c staticlist.h
	${CC} ${CFLAGS} -c $<
staticlist.o:staticlist.c staticlist.h
	${CC} ${CFLAGS} -c $<
.PHONY:clean
clean:
	rm -f $@ ${OBJS}
