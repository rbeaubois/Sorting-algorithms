#ifndef QUICK_H
#define QUICK_H

#include "../comparator.h"

class Quick : public Comparator {
private:
    virtual unsigned int* sort(unsigned int data[], int len);
};

#endif
