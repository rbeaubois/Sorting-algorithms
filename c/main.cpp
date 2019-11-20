#include <iostream>

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <omp.h>

#include "file2tab.h"
#include "bubble/bubble.h"
#include "trident/trident.h"
#include "radix/radix.h"

#define NB_THREADS 4
#define NB_DATA (1<<20)

#define TRIDENT

void loadFile(char* name, unsigned int data[], int len) {
    FILE* f = fopen(name, "r");
    if (f == NULL) {
        cout << "Error opening file" << endl;
        exit(0);
    }
    for(int i = 0; i < len; i++) {
        fscanf(f, "%u", data+i);
    }
    fclose(f);
}

int main(int argc, char* argv[]) {

	//init
	omp_set_num_threads(NB_THREADS);

    //Load random data
    unsigned int data[NB_DATA];
	file2tab f2t("../data/random.txt", NB_DATA, data);

    //Test sort
#ifdef BUBBLE
    Bubble s;
#endif
#ifdef RADIX
    Radix s;
#endif
#ifdef TRIDENT
    Trident s;
#endif
	int duration = s.process(data, NB_DATA);
    cout << "Execution time: \t" << duration << "us" << endl;
    return 0;
}
