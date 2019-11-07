#include "dataout.h"

void DataOut::do_print(){
    ofstream fdata;
    sc_uint<DATA_TYPE> data; 

    fdata.open("Sorted_array.txt");

	while( true ){
		data = e.read();
		fdata << to_string(data) << endl;
	}
	fdata.close();
}

