CC = gcc
CFLAGS = -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
COBJS = linklist.o linkstack.o compute.o
TOBJS = linklist.o linkstack.o transfrom.o
.PHONY:all
all:compute transfrom
compute:${COBJS}
	${CC} $^ ${LDFLAGS} $@
transfrom:${TOBJS}
	${CC} $^ ${LDFLAGS} $@
linklist.o:linklist.c linklist.h
	${CC} ${CFLAGS} $<
linkstack.o:linkstack.c linkstack.h
	${CC} ${CFLAGS} $<
compute.o:compute.c linkstack.h
	${CC} ${CFLAGS} $<
transfrom.o:transfrom.c linkstack.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf ${TOBJS} ${COBJS} compute transfrom
