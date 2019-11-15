#ifndef BUBBLE_H
#define BUBBLE_H

#include "../comparator.h"

/* ********************************* Implement comparator class  **************************************** */
class Bubble : public Comparator {
private:
    virtual unsigned int* sort(unsigned int data[], int len);
};

#endif