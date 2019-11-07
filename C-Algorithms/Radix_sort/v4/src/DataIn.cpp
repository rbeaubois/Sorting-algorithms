#include "datain.h"

void DataIn::do_gen(){
    ifstream fdata;
    string tmp;
    string sync;
    sc_uint<DATA_TYPE> data;
   
    fdata.open("../../../Data/random.txt");

	while( !fdata.eof() ){
    		getline(fdata, tmp, '\r');
    		cin >> sync;
		data = stoi(tmp, NULL, 2);
        	tmp.erase();
		s.write(data);
	}
     fdata.close();
}
