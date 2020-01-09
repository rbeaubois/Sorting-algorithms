#include "Constants.h"
#define SC_INCLUDE_FX
#include "systemc.h"


SC_MODULE(CheckSort)
{
	sc_in<bool> clk;
	sc_fifo_in	< sc_uint<DATA_TYPE> > e;
	sc_fifo_out	< sc_uint<DATA_TYPE> > s;

	SC_CTOR(CheckSort)
	{
		SC_CTHREAD(do_check, clk);
	}

    void do_check();

};
