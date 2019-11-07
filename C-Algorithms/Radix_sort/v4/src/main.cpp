#include "radix_sort.h"
#include "datain.h"

#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char * argv []){
	cout << "Init components..." << endl;
		DataIn      		gene	("Data_to_sort");
		Radix_sort 		sort 	("Radix_sorting");
		Check_sort 		check	("Check_sorting");
		DataOut			term	("Data_sorted");

	cout << "Create link signals..." << endl;
		sc_clock 		sclk("clk10",10, SC_NS);
		sc_fifo< sc_uint<DATA_TYPE> >	s1("FIFO_1", ARRAY_SIZE);
		sc_fifo< sc_uint<DATA_TYPE> >	s2("FIFO_2", ARRAY_SIZE);
		sc_fifo< sc_uint<DATA_TYPE> >	s3("FIFO_3", ARRAY_SIZE);

	cout << "Mapping components..." << endl;
		DataIn.s(s1);	

		Radix_sort.clk(sclk);
		Radix_sort.i_data(s1);
		Radix_sort.o_data(s2);
		
		Check_sort.e(s2);
		Check_sort.s(s3);

		DataOut.e(s3);

	cout << "Running circuit simulation..." << endl;
		sc_start(100,SC_MS);
	cout << "End circuit simulation..." << endl;

    return 0;
}
