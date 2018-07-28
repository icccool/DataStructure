GCC = gcc
CFLAGS = -O2 -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
OBJS = CircleList.o CircleListMain.o
CircleList:${OBJS}
	${GCC} $^ ${LDFLAGS} $@
CircleList.o:CircleList.c CircleList.h
	${GCC} ${CFLAGS} $<
CircleListMain.o:CircleListMain.c CircleList.h
	${GCC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf $@ ${OBJS}

