#!/bin/bash
val=8192
unset LC_ALL
export LC_NUMERIC=C

# Archivo para almacenar los datos de tiempo de ejecución
echo "" > dgemv.dat

# Ejecutar dgemv para cada número de hilos de 1, 2, 4 y 8
for i in 1 2 4 8
do
    sum=0
    for j in {1..10}
    do
        time=$(./dgemv "$i" "$val" "$val" 1 off | awk '/^Data/ { print $3 }')
        sum=$(echo "$sum + $time" | bc -l)
    done
    avg=$(echo "scale=6; $sum / 10" | bc -l)
    printf "%d %.6f\n" "$i" "$avg" >> dgemv.dat
    echo "$i $val test finished"
done

gnuplot < dgemv.p

