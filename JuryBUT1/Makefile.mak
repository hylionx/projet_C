juryBUT1: jury.o moyennes.o
	gcc -o juryBUT1 jury.o moyennes.o

jury.o: jury.c moyennes.h
	gcc -c jury.c -Wall

moyennes.o: moyennes.c moyennes.h
	gcc -c moyennes.c -Wall

clean:
	del juryBUT1.exe jury.o moyennes.o
