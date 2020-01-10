#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <fstream>  
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../comparator.h"

#define AVERAGING   25	// Number of runs for a fixed number of data
#define DATA_STEP   256	// Increase step for the number of data
#define NB_SETS		10	// Number of data sets to run

// Randomize an array of size n
	void randomize(unsigned int* data, int n);
// Benchmarking a sort algorithm
	void runBenchmark(Comparator *s, unsigned int* data, int n, string sort);
// Print progress
	void print_progress(unsigned int timer, int n);

#endif