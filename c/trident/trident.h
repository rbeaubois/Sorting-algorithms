#ifndef TRIDENT_H
#define TRIDENT_H

#include "../comparator.h"

class Trident : public Comparator {
	private:
		unsigned int* sort(unsigned int data[], int len);
};

#endif
