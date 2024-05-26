#/**
# @brief Makefile for ddot: sample program for cblas_ddot function
# @author Julio Jos&eacute; &Aacute;guila Guerrero
# @date March 24th, 2022
# */
CC = gcc
FLAGS = -O3 -s -pipe -Wall -fomit-frame-pointer -march=native \
	-I../array -w
LIBRARY = ../Array/array.a
EXEC = ddot

all: ${EXEC}

${EXEC}: ${EXEC}.c
	${CC} ${FLAGS} -c ${EXEC}.c -fopenmp
	${CC} ${FLAGS} -o ${EXEC} ${EXEC}.o ${LIBRARY} -lblas -fopenmp
clean:
	(rm -f core)
	(rm -f *.o)
	(rm -f *~)
	(rm ${EXEC})