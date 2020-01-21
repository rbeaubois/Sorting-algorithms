set datafile separator ";"
set term png size 1920,1080
set output '../bench_results/trident.png'
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
plot "trident_results.csv" using 1:4 title 'trident min duration' with line
set title "PYNQ CPU Benchmark results"
plot "trident_results_pynq.csv" using 1:4 title 'trident min duration' with line
unset multiplot
