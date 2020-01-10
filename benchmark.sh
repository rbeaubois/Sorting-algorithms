#!/bin/bash
clear

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

./c/main $sort bench $dat_nb

cd bench_results && gnuplot plot.gnu