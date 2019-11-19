#include "CheckSort.h"

void CheckSort::do_check(){
	sc_uint<DATA_TYPE> last_data;
	sc_uint<DATA_TYPE> data;
	last_data = e.read();
	s.write(last_data);
	while( true ){
		for(int i= 0 ; i < ARRAY_SIZE ;  i++);
		data = e.read();

		if(last_data > data)
			cout << "Wrong sorting..." << endl;

		s.write(data);
	}
}
