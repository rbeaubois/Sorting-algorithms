set datafile separator ";"
set xlabel 'Number of elements'
set ylabel 'Execution time (us)'
set grid
plot "radix_results.csv" using 1:2 title 'Radix sort' with line, "radix_results.csv" using 1:3 title 'Max duration' with line, "radix_results.csv" using 1:4 title 'Min duration' with line
pause -1
