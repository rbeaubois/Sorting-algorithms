#include "DataIn.h"

using namespace std;

void DataIn::do_gen(){
    ifstream fdata;
    string tmp_s;
    unsigned int tmp_num;
    sc_uint<DATA_TYPE> data;
    int i = 0;
    fdata.open("../../data/random.txt");
    cout << "Start reading data" << "\n";

	while(i < ARRAY_SIZE){
        getline(fdata, tmp_s);
        tmp_num = (unsigned int)stoul(tmp_s, NULL, 10);
        tmp_s.clear();
        data    = tmp_num;
        s.write(data);
        i++;
	}
}