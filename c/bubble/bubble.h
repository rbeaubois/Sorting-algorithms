#ifndef BUBBLE_H
#define BUBBLE_H

#include "../comparator.h"

class Bubble : public Comparator {
private:
    virtual unsigned int* sort(unsigned int data[], int len);
};

#endif
