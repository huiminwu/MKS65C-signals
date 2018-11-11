all: sig.o
	gcc -o Sig sig.o

sig.o: sig.c
	gcc -c sig.c

run:
	./Sig
