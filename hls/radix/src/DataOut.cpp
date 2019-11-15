#include "DataOut.h"

void DataOut::do_print(){
    ofstream fdata;
    unsigned int tmp;
    sc_uint<DATA_TYPE> data; 

    fdata.open("Sorted_array.txt");

	while( true ){
		data = e.read();
		tmp = data;
		fdata << std::to_string(tmp) << endl;
	}
	fdata.close();
}

