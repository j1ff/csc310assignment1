INCLUDE_DIR			:= /home/keith/proj/assignment1
CC					:= g++
CFLAGS				:= -I{INCLUDE_DIR}

OBJS				:= list.o myException.o 

mainExc: main.cpp ${OBJS}
	${CC} -o $@ $^ ${CFLAGS}

list.o: list.cpp list.h 
	${CC} -c -o $@ $< ${CFLAGS}

myException.o: myException.cpp myException.h 
	${CC} -c -o $@ $< ${CFLAGS}



.PHONY: clean

clean: 
	rm *.o mainExc 