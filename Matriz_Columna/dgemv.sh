#!/bin/bash
val=32
unset LC_ALL
export LC_NUMERIC=C

# Archivo para almacenar los datos de tiempo de ejecución
echo "" > dgemv.dat

# Ejecutar dgemv para cada número de hilos de 2 4 8 y 16
for i in {2,4,8,16}
do
    ./dgemv "${i}" "${val}" "${val}" 1 off | awk $info '/^Data/ { print $2 " " $3}' >> dgemv.dat
    echo "${i} ${val} test finished"
done

gnuplot < dgemv.p