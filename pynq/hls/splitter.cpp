#include "splitter.hpp"

void sort_recur(unsigned int data[], unsigned int a, unsigned int b,
		unsigned int medians[], unsigned int imedians[], unsigned int k) {
	if (b < a || b-a <=0) return;
	unsigned int i;
	unsigned int key = data[a];
	unsigned int ikey = a;
	for(i = a+1; i < b; i++) {
		if (data[i] < key) {
			data[ikey] = data[i];
			ikey++;
			data[i] = data[ikey];
		}
	}
	data[ikey] = key;
	for(i = 0; i < k; i++) {
		unsigned int imed = imedians[i];
		if (a <= imed && imed <= b) {
			if (ikey == imed) {
				medians[i] = key;
			} else if (imed < ikey) {
				if (medians[i] == 0)
					sort_recur(data, a, ikey, medians, imedians, k);
			} else if (imed > ikey) {
				if (medians[i] == 0)
					sort_recur(data, ikey+1, b, medians, imedians, k);
			}
		}
	}
}
