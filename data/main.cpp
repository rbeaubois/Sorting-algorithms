#include <iostream>
#include <chrono>
#include <unistd.h>


using namespace std;


#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

void generateFile(int n, bool hex) {
    srand(time(NULL));
    FILE* f = fopen("random.txt", "w");
    for(int i = 0; i < n; i++) {
        unsigned int v = (rand()&0xFF) | (rand()&0xFF)<<8 |
        (rand()&0xFF)<<16 | (rand()&0xFF)<<24;
        if (!hex)
            fprintf(f, "%u\n", v);
        else
            fprintf(f, "0x%x\n", v);
    }
    fclose(f);
}

int main(int argc, char *argv[]) {
    bool hex = false;
    unsigned long nbr_data = 64000;
    if (argc == 3) {
        hex = argv[2][0]=='h';
    }
    if (argc >= 2) {
        nbr_data = atoi(argv[1]);
    }
    generateFile(nbr_data, hex);
    return 0;
}
