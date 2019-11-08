#ifndef COMPARATOR_H
#define COMPARATOR_H

class Comparator {
private:
    virtual unsigned int* sort(unsigned int data[], int len);
    void check(unsigned int data[], int len);
public:
    int process(unsigned int data[], int len);
};

#endif
