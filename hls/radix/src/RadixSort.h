#define SC_INCLUDE_FX
#include "systemc.h"
#include "Constants.h"

SC_MODULE(RadixSort)
{
  sc_in         <bool>                    clk;
  sc_fifo_in    < sc_uint<DATA_TYPE> >    i_data;
  sc_fifo_out   < sc_uint<DATA_TYPE> >    o_data;

	SC_CTOR(RadixSort)
	{
		SC_CTHREAD(do_sort, clk);
	}

  void do_sort();

 };
