#include <iostream>

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <omp.h>

#include "file2tab.h"
#include "bubble/bubble.h"
#include "trident/trident.h"
#include "insertion/insertion.h"
#include "quick/quick.h"
#include "tim/tim.h"
#include "selection/selection.h"
#include "radix/radix.h"

#define NB_THREADS 4
#define NB_DATA 8

#define TRIDENT

namespace choix {

    enum algo {
        Bubble=1,
        Insertion,
        Quick,
        Radix,
        Selection,
        Tim,
        Trident
    };
}

void loadFile(char* name, unsigned int data[], int len) {
    FILE* f = fopen(name, "r");
    if (f == NULL) {
        cout << "Error opening file" << endl;
        exit(0);
    }
    for(int i = 0; i < len; i++) {
        unsigned int v;
        fscanf(f, "%u", &v);
        data[i] = v;
    }
    fclose(f);
}

int main(int argc, char* argv[]) {

	//init
	omp_set_num_threads(NB_THREADS);

    Comparator* s;

    //Algo choice menu
    int choice;
    cout << "Choose your algorithm:\n\n";
    cout << "1 - Bubble.\n";
    cout << "2 - Insertion.\n";
    cout << "3 - Quick.\n";
    cout << "4 - Radix.\n";
    cout << "5 - Selection.\n";
    cout << "6 - Tim.\n";
    cout << "7 - Trident.\n\n";
    cout << "Choice --> ";
    cin >> choice;
    cout << endl;

    switch (choice) {
    case choix::Bubble:
        s = new Bubble();
        break;
    case choix::Insertion:
        s = new Insertion();
        break;
    case choix::Quick:
        s = new Quick();
        break;
    case choix::Radix:
        s = new Radix();
        break;
    case choix::Selection:
        s = new Selection();
        break;
    case choix::Tim:
        s = new Tim();
        break;
    case choix::Trident:
        s = new Trident();
        break;
    default:
        cout << "Invalid choice.\n";
    }

    //Load random data
    unsigned int data[NB_DATA];
	file2tab f2t("../data/random.txt", NB_DATA, data);


	int duration = s->process(data, NB_DATA);
    cout << "Execution time: \t" << duration << "us" << endl;
    return 0;
}
