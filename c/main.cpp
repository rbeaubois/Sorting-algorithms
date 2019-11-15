#include <iostream>
#include <unistd.h>

using namespace std;
#include <stdio.h>
#include <stdlib.h>

#include "bubble/bubble.h"
#include "radix/radix.h"

#define NBR_DATA 64000

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

    //Load random data
    char name[] = "../data/random.txt";
    unsigned int data[NBR_DATA];
    loadFile(name, data, NBR_DATA);

    //Test sort
    Bubble b;
    Radix r;
    //cout << "Result: " <<  b.process(data, NBR_DATA) << endl;
    cout << "Result: " <<  r.process(data, NBR_DATA) << endl;
    return 0;
}
