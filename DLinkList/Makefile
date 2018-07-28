CC = gcc
CFLAGS = -Wall -std=c99 -O2 -g -c
LDFLAGS = -Wall -std=c99 -O2 -g -o
OBJS = DLinkList.o Main.o
dlinklist:${OBJS}
	${CC} $^ ${LDFLAGS} $@
DLinkList.o:DLinkList.c DLinkList.h
	${CC} ${CFLAGS} $<
Main.o:Main.c DLinkList.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf ${OBJS} $@
