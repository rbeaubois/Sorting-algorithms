#include "datain.h"

void DataIn::do_gen(){
    ifstream fdata;
    string tmp;
    sc_uint<DATA_TYPE> data;
    fdata.open("../../../Data/random.txt");
    getline(fdata, tmp, 'r');

	while( true ){
        s.write(data);
	}
}