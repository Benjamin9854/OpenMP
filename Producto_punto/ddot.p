set term post eps enhanced color solid lw 2 size 6.0, 4.0 "Arial" 24
set output "ddot.eps"
set title "Tiempo ejecucion paralela" noenhanced
set xlabel "P ({/Ital cantidad hilos OpenMP})"
set ylabel "T ({/Ital segundos})"
set grid
set key left top
set xtics("2" 2, "4" 4, "8" 8, "16" 16)
plot "ddot.dat" using 1:2 title "Runtime" with lines
