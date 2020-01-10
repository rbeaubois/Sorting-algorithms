set datafile separator ";"
set xlabel 'Number of elements'
set ylabel 'Execution time (us)'
set grid
set key box
set title "Benchmark results"
set key height 1
set key top left
set key box spacing 1.5
plot "bubble_results.csv" using 1:2 title 'bubble sort' with line, "bubble_results.csv" using 1:3 title 'Max duration' with line, "bubble_results.csv" using 1:4 title 'Min duration' with line
pause -1
