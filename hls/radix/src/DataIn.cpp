#include "DataIn.h"

using namespace std;

void DataIn::do_gen(){
    ifstream fdata;
    string tmp;
    string buf;
    sc_uint<DATA_TYPE> data;
    fdata.open("../../data/random.txt");
    getline(fdata, tmp, 'r');
    cin >> buf;

	while( true ){
        s.write(data);
	}
}
