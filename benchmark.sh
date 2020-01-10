#!/bin/bash
clear
rm bench_results/plot.gnu
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

echo "Enter maximum amount of data"
echo
read dat_nb

cd c
./main "$sort" bench "$dat_nb"
cd ..
touch plot.gnu
cat bench_results/plt_tmp.txt >> bench_results/plot.gnu
echo -e "plot \"${sort}_results.csv\" using 1:2 title '${sort} sort' with line, \"${sort}_results.csv\" using 1:3 title 'Max duration' with line, \"${sort}_results.csv\" using 1:4 title 'Min duration' with line
pause -1" >> bench_results/plot.gnu
cd bench_results && gnuplot plot.gnu
