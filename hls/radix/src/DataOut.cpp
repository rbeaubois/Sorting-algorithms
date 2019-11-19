#include "DataOut.h"

void DataOut::do_print(){
    ofstream fdata;
    sc_uint<DATA_TYPE> data; 

    fdata.open("Sorted_array.txt");

	while( true ){
		data = e.read();
		fdata << data<< endl;
	}
	fdata.close();
}

