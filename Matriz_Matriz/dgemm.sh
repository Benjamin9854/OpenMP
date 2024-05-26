#!/bin/bash
val=4096
unset LC_ALL
export LC_NUMERIC=C

# Archivo para almacenar los datos de tiempo de ejecución
echo "" > dgemm.dat

# Ejecutar dgemm para cada número de hilos de 2 4 8 y 16
for i in {2,4,8,16}
do
    ./dgemm "${i}" "${val}" "${val}" "${val}" 1 off | awk $info '/^Data/ { print $2 " " $3}' >> dgemm.dat
    echo "${i} ${val} test finished"
done

gnuplot < dgemm.p