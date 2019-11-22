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

void bitonicsort(unsigned int* data, unsigned int step);
void batcheroddeven(unsigned int* const data, unsigned int const step);
inline void swapcmp(unsigned int* a, unsigned int* b);

#endif
