#ifndef TRIDENT_H
#define TRIDENT_H

#include "../comparator.h"

class Trident : public Comparator {
	public:
		Trident();
		~Trident();
	private:
		unsigned int* sort(unsigned int data[], int len);
};

#endif
