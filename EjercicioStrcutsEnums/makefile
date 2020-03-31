all: programa
programa: main Matrices
	gcc -o Matrices main.o Matrices.o
Main: main.c Matrices.h
	gcc -c main.c
Matrices: Matrices.c Matrices.h
	gcc -c Matrices.c 