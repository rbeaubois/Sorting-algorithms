#ifndef INSERTION_H
#define INSERTION_H
#include "../comparator.h"

class Insertion : public Comparator{
private:
    virtual unsigned int* sort(unsigned int data[], int len);
};

#endif
