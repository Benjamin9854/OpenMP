#!/bin/bash
val=8388608
unset LC_ALL
export LC_NUMERIC=C

# Archivo para almacenar los datos de tiempo de ejecución
echo "" > ddot.dat

# Ejecutar ddot para cada número de hilos de 2 4 8 y 16
for i in {2,4,8,16}
do
    ./ddot "${i}" "${val}" 1 off | awk $info '/^Data/ { print $2 " " $3}' >> ddot.dat
    echo "${i} ${val} test finished"
done

gnuplot < ddot.p