#include "Constants.h"
#include "RadixSort.h"
#include "DataIn.h"
#include "CheckSort.h"
#include "DataOut.h"

#include <iostream>

using namespace std;

int sc_main (int argc, char * argv []){
	
	cout << "Init components..." << endl;
		DataIn      	gene	("Data_to_sort");
		RadixSort 		sort 	("Radix_sorting");
		CheckSort 		check	("Check_sorting");
		DataOut			term	("Data_sorted");

	cout << "Create link signals..." << endl;
		sc_fifo< sc_uint<DATA_TYPE> >	s1("FIFO_1", ARRAY_SIZE);
		sc_fifo< sc_uint<DATA_TYPE> >	s2("FIFO_2", ARRAY_SIZE);
		sc_fifo< sc_uint<DATA_TYPE> >	s3("FIFO_3", ARRAY_SIZE);

	cout << "Mapping components..." << endl;
		//gene.clk(sclk);
		//sort.clk(sclk);
		//check.clk(sclk);
		//term.clk(sclk);

		gene.s(s1);	

		sort.e(s1);
		sort.s(s2);
		
		check.e(s2);  
		check.s(s3);

		term.e(s3); 

		cout << "Running circuit simulation..." << endl;
		//sc_start(100,SC_MS);
		cout << "End circuit simulation..." << endl;

    return 0;
}
