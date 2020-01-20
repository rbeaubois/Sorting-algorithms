set datafile separator ";"
set term png size 1920,1080
set output '../bench_results/radix.png'
set xlabel 'Number of elements'
set ylabel 'Execution time (us)'
set grid
set key box
set key height 1
set key top left
set key box spacing 1.5
set multiplot layout 1,2
set title "CPU Benchmark results"
set label "#Data set size: 2^{2} (4) to 2^{16} (65536)\n#Random sets benched per step:10\n#Averaging per set:25" at graph 0.6, graph 0.95
plot "radix_results.csv" using 1:2 title 'radix sort' with line, "radix_results.csv" using 1:3 title 'radix max duration' with line, "radix_results.csv" using 1:4 title 'radix min duration' with line
set title "PYNQ CPU Benchmark results"
plot "radix_results_pynq.csv" using 1:2 title 'radix sort' with line, "radix_results_pynq.csv" using 1:3 title 'radix max duration' with line, "radix_results_pynq.csv" using 1:4 title 'radix min duration' with line
unset multiplot
