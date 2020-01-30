#ifndef LIBCSORTER_H
#define LIBCSORTER_H

#include "../comparator.h"

class LibcSorter : public Comparator {
private:
    virtual unsigned int* sort(unsigned int data[], int len);
};

#endif
