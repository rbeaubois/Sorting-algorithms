#include "Constants.h"
#define SC_INCLUDE_FX
#include "systemc.h"

SC_MODULE(RadixSort)
{
  sc_fifo_in    < sc_uint<DATA_TYPE> > e;
  sc_fifo_out   < sc_uint<DATA_TYPE> > s;

	SC_CTOR(RadixSort)
	{
		SC_THREAD(do_sort);
	}

  void do_sort();

 };
