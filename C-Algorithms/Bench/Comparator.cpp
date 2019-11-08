#include "Comparator.h"

#include <chrono>
using namespace std;

int Comparator::process(unsigned int d[], int len) {
    auto start = chrono::steady_clock::now();
    sort(d, len);
    auto end = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end-start).count();
}
