CFLAGS = -Wall
STD = -std=c99
OBJS = seqmain.o seqlist.o 
seqlist:${OBJS}
	gcc -o $@ ${CFLAGS} ${OBJS} ${STD}
seqmain.o:seqmain.c seqlist.h
	gcc seqmain.c ${CFLAGS} ${STD} -c
seqlist.o:seqlist.c 
	gcc seqlist.c ${CFLAGS} ${STD} -c

clean:
	rm -f seqlist ${OBJS}
