CFLAGS = -Wall -std=c99 -g -c
LDFLAGS = -Wall -std=c99 -g -o
OBJS = linklist.o linkqueue.o MGraph.o main.o
MGraph:${OBJS}
	${CC} $^ ${LDFLAGS} $@
MGraph.o:MGraph.c MGraph.h 
	${CC} ${CFLAGS} $<
linkqueue.o:linkqueue.c linkqueue.h
	${CC} ${CFLAGS} $<
linklist.o:linklist.c linklist.h
	${CC} ${CFLAGS} $<
main.o:main.c MGraph.h
	${CC} ${CFLAGS} $<
.PHONY:clean
clean:
	${RM} -rf MGraph *.o
