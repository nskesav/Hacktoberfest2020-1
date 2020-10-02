a.out:rr.o functions.o
	gcc -o a.out rr.o functions.o
rr.o:rr.c makefile.h
	gcc -c rr.c
functions.o:functions.c makefile.h
	gcc -c functions.c
clean:
	del a.out rr.o functions.o
