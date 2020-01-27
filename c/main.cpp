#include <iostream>

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <omp.h>

#include "benchmark/benchmark.h"

#include "bubble/bubble.h"
#include "trident/trident.h"
#include "insertion/insertion.h"
#include "quick/quick.h"
#include "tim/tim.h"
#include "selection/selection.h"
#include "radix/radix.h"
#include "splitter/splitter.h"

#define NB_THREADS 8
#define NB_DATA (1<<16)
#define NBR_MED 10

// Data splitter tests
	void foo(unsigned int* data);

int main(int argc, char* argv[]) {

	//init
	omp_set_num_threads(NB_THREADS);

    //Load random data
    unsigned int* data = (unsigned int*)malloc(sizeof(unsigned int)*NB_DATA);
	if(data == NULL){
        fprintf(stderr, "Failed to allocate memory for data to sort");
        exit(1);
    }
	randomize(data, NB_DATA);

    Comparator* s;

	if (argc < 2) {
		printf("Please use one of the following algorithm:\n");
		printf(	"\tbubble\n" \
				"\tinsertion\n" \
				"\tquick\n" \
				"\tradix\n" \
				"\tselection\n" \
				"\ttim\n" \
				"\ttrident\n");
		exit(1);
	}

	if (!strcmp(argv[1], "bubble")) {
		s = new Bubble();
	} else if (!strcmp(argv[1], "insertion")) {
		s = new Insertion();
	} else if (!strcmp(argv[1], "quick")) {
		s = new Quick();
	} else if (!strcmp(argv[1], "radix")) {
		s = new Radix();
	} else if (!strcmp(argv[1], "selection")) {
		s = new Selection();
	} else if (!strcmp(argv[1], "tim")) {
		s = new Tim();
	} else if (!strcmp(argv[1], "trident")) {
		s = new Trident();
	} else if (!strcmp(argv[1], "splitter")) {
		foo(data);
		exit(0);
	} else {
		printf("Invalid choice");
		exit(1);
	}

	if (!strcmp(argv[2], "bench"))
	{
		cout << "Start of benchmark" << endl;
		runBenchmark(s, data, argv[1]);
		cout << "End of benchmark" << endl;
	}

	int duration = s->process(data, NB_DATA);
    cout << "Execution time: \t" << duration << "us" << endl;
	
	free(data);
	exit(0);
}



// Generate sorted blocks to avoid merge when using FPGA
void foo(unsigned int* data) {
    unsigned int medians[NBR_MED];
    unsigned int imedians[NBR_MED];
    for(int i = 0; i < NBR_MED; i++) {
        imedians[i] = (i+1)*(NB_DATA/(NBR_MED+1));
        medians[i] = 0;
    }
    Splitter s = Splitter(medians, imedians, NBR_MED);

    cout << "Spliting..." << endl;
    cout << "Split time: " << s.process(data, NB_DATA) << endl;

    Quick q = Quick();
    for(int i = 0; i < NBR_MED+1; i++) {
        //cout << "Sort: " << (i==0?0:0+imedians[i-1]) << " " << (i==NBR_MED?NB_DATA:imedians[i]) << endl;
        cout << "Sort time: " << q.process(i==0?data:data+imedians[i-1]+1, (i==NBR_MED?NB_DATA:imedians[i])-(i==0?0:imedians[i-1]+1)) << endl;
    }

    q.check(data, NB_DATA);

    cout << "Resultats:" << endl;
    for(int i = 0; i < NBR_MED; i++) {
        cout << s.medians[i] << endl;
    }
}
