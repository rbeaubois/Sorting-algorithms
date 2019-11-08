#ifndef BUBBLE_H
#define BUBBLE_H

class Bubble : public Comparator{
private:
    virtual unsigned int* sort(unsigned int data[], int len);
};

#endif
