#include "systemc.h"


SC_MODULE(Check_sort)
{
	sc_fifo_in	< sc_uint<DATA_TYPE> > e;
	sc_fifo_out	< sc_uint<DATA_TYPE> > s;

    void do_gen();

	SC_CTOR(Check_sort)
	{
		SC_THREAD(do_check);
	}
