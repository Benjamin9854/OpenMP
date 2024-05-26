#/**
# \file
# @brief Makefile for dgemm: sample program for cblas_dgemm function
# @author Julio Jos&eacute; &Aacute;guila Guerrero
# @date May 09th, 2024
# */
CC = gcc
FLAGS = -O3 -s -pipe -Wall -fomit-frame-pointer -march=native \
	-I../array -w
LIBRARY = ../Array/array.a
EXEC = dgemm

all: ${EXEC}

${EXEC}: ${EXEC}.c
	${CC} ${FLAGS} -c ${EXEC}.c -fopenmp
	${CC} ${FLAGS} -o ${EXEC} ${EXEC}.o ${LIBRARY} -lblas -fopenmp
	
clean:
	(rm -f core)
	(rm -f *.o)
	(rm -f *~)
	(rm ${EXEC})