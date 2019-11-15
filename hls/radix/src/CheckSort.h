#include "Constants.h"
#include "systemc.h"


SC_MODULE(CheckSort)
{
	sc_fifo_in	< sc_uint<DATA_TYPE> > e;
	sc_fifo_out	< sc_uint<DATA_TYPE> > s;

	SC_CTOR(CheckSort)
	{
		SC_THREAD(do_check);
	}

    void do_check();

};
