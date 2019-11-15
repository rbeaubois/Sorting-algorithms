#ifndef SELECTION_H
#define SELECTION_H

#include "../comparator.h"

class Selection : public Comparator{
private:
    virtual unsigned int* sort(unsigned int data[], int len);
};

#endif

