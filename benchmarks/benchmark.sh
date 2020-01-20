#!/bin/bash
clear
rm plot.gnu
good_sort=false;

while [ "$good_sort" == false ]
do
	echo "Enter sorting algorithm:"
	echo
	read sort
	if [ "$sort" = "bubble" ] || [ "$sort" = "insertion" ] || [ "$sort" = "quick" ] || [ "$sort" = "radix" ] || [ "$sort" = "selection" ] || [ "$sort" = "tim" ] || [ "$sort" = "trident" ]
	then
		good_sort=true
	else
		good_sort=false
		echo "Bad syntax, try again"
		echo
	fi
done

dat_nb = 65536

cd c
./main "$sort" bench "$dat_nb"
cd ..
info="$(awk 'NR==1' ${sort}_results.csv)"
touch plot.gnu
cat plt_tmp.txt >> plot.gnu
sed -i -e "s/image/$sort/g" plot.gnu
echo -e "set title \"CPU Benchmark results\"" >> plot.gnu
echo -e "set label \"${info}\" at graph 0.6, graph 0.95" >> plot.gnu
echo "Choose what to plot:"
select plot_choice in Min Max All; do
    case $plot_choice in
        Min ) echo -e "plot \"${sort}_results.csv\" using 1:4 title '${sort} min duration' with line" >> plot.gnu;
		echo -e "set title \"PYNQ CPU Benchmark results\"" >> plot.gnu;
		echo -e "plot \"${sort}_results_pynq.csv\" using 1:4 title '${sort} min duration' with line" >> plot.gnu; break;;
        Max ) echo -e "plot \"${sort}_results.csv\" using 1:3 title '${sort} max duration' with line" >> plot.gnu;
		echo -e "set title \"PYNQ CPU Benchmark results\"" >> plot.gnu;
		echo -e "plot \"${sort}_results_pynq.csv\" using 1:3 title '${sort} max duration' with line" >> plot.gnu; break;;
		All ) echo -e "plot \"${sort}_results.csv\" using 1:2 title '${sort} sort' with line, \"${sort}_results.csv\" using 1:3 title '${sort} max duration' with line, \"${sort}_results.csv\" using 1:4 title '${sort} min duration' with line" >> plot.gnu;
		echo -e "set title \"PYNQ CPU Benchmark results\"">> plot.gnu;
		echo -e "plot \"${sort}_results_pynq.csv\" using 1:2 title '${sort} sort' with line, \"${sort}_results_pynq.csv\" using 1:3 title '${sort} max duration' with line, \"${sort}_results_pynq.csv\" using 1:4 title '${sort} min duration' with line" >> plot.gnu;
		 break;;
    esac
done

echo -e "unset multiplot" >> plot.gnu
cd benchmarks && gnuplot plot.gnu && feh $sort.png

