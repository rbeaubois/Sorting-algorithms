set datafile separator ";"
set term png size 1920,1080 font 'Arial,16'
set output '../bench_results/insertion.png'
set xlabel 'Number of elements'
set ylabel 'Execution time (us)'
set grid
set key box
set key height 1
set key top left
set key box spacing 1.5
set multiplot layout 1,2
set title "CPU Benchmark results"
set label "#Data set size: 2^{2} (4) to 2^{16} (65536)\n#Random sets benched per step:10\n#Averaging per set:25" at graph 0.54, graph 0.95
plot "insertion_results.csv" using 1:2 title 'insertion sort' with line, "insertion_results.csv" using 1:3 title 'insertion max duration' with line, "insertion_results.csv" using 1:4 title 'insertion min duration' with line
set title "PYNQ CPU Benchmark results"
plot "insertion_results_pynq.csv" using 1:2 title 'insertion sort' with line, "insertion_results_pynq.csv" using 1:3 title 'insertion max duration' with line, "insertion_results_pynq.csv" using 1:4 title 'insertion min duration' with line
unset multiplot
