#ifndef TIM_H
#define TIM_H
#include "../comparator.h"

class Tim : public Comparator{
private:
    virtual unsigned int* sort(unsigned int data[], int len);
};

#endif
