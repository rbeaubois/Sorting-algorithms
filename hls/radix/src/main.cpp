#include "Constants.h"
#include "RadixSort.h"
#include "DataIn.h"
#include "CheckSort.h"
#include "DataOut.h"

#include <iostream>

using namespace std;

int sc_main (int argc, char * argv []){
	
	cout << "Init components..." << endl;
		DataIn      		gene	("Data_to_sort");
		RadixSort 		sort 	("Radix_sorting");
		CheckSort 		check	("Check_sorting");
		DataOut			term	("Data_sorted");

	cout << "Create link signals..." << endl;
		sc_clock 		sclk("clk10",10, SC_NS);
		sc_fifo< sc_uint<DATA_TYPE> >	s1("FIFO_1", ARRAY_SIZE);
		sc_fifo< sc_uint<DATA_TYPE> >	s2("FIFO_2", ARRAY_SIZE);
		sc_fifo< sc_uint<DATA_TYPE> >	s3("FIFO_3", ARRAY_SIZE);

	cout << "Mapping components..." << endl;
		gene.s(s1);	

		sort.clk(sclk);
		sort.i_data(s1);
		sort.o_data(s2);
		
		check.e(s2);
		check.s(s3);

		term.e(s3);

	cout << "Running circuit simulation..." << endl;
		sc_start(100,SC_MS);
	cout << "End circuit simulation..." << endl;

    return 0;
}
