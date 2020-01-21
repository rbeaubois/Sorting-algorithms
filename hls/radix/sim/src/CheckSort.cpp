#include "CheckSort.h"

void CheckSort::do_check(){
	sc_uint<DATA_TYPE> last_data;
	sc_uint<DATA_TYPE> data;
	sc_uint<DATA_TYPE> debug_counter = 0;

	last_data = e.read();
	s.write(last_data);
	debug_counter++;

	while( true ){
		for(sc_uint<ADDR_SIZE> i= 0 ; i < ARRAY_SIZE ;  i++);
		data = e.read();
		debug_counter++;


		if(last_data > data)
			cout << "Wrong sorting at index ->" << debug_counter-1 << endl;

		last_data = data;
		s.write(data);
	}
}
