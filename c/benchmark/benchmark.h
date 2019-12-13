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

#define AVERAGING   10
#define DATA_STEP   128

// Randomize an array of size n
	void randomize(unsigned int* data, int n);
// Benchmarking a sort algorithm
	void runBenchmark(Comparator *s, unsigned int* data, int n, string sort);

#endif