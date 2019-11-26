#ifndef SPLITTER_H
#define SPLITTER_H

#include "../comparator.h"

class Splitter : public Comparator {
public:
    Splitter(unsigned int* med, unsigned int* imed, unsigned int nbr_med);
private:
    virtual unsigned int* sort(unsigned int data[], int len);
public:
    unsigned int* medians;//Medians values output
private:
    unsigned int* imedians;//Indexes of medians to search
    unsigned int nbr_median;//Number of medians
};

#endif
