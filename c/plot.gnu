set title "CPU Benchmark results"
set label "" at graph 0.54, graph 0.95
plot "radix_results.csv" using 1:4 title 'radix min duration' with line
set title "PYNQ CPU Benchmark results"
plot "radix_results_pynq.csv" using 1:4 title 'radix min duration' with line
unset multiplot
