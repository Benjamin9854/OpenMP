set term post eps enhanced color solid lw 1 size 5.0, 3.5 "Arial" 24
set output "dgemm.eps"
set title "Tiempo ejecucion paralela" noenhanced
set xlabel "P ({/Ital cantidad hilos OpenMP})"
set ylabel "T ({/Ital segundos})"
set key left
set grid
set xtics("2" 2, "4" 4, "8" 8, "16" 16)
plot "dgemm.dat" using 1:2 title "runtime" with lines