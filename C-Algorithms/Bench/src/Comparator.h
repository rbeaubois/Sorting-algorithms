#indef COMPARAOTR_H
#define COMPARAOTR_H

class Comparator {
private:
    virtual unsigned int* sort(unsigned int data[], int len);
public:
    int process(unsigned int data[], int len);
};

#endif
