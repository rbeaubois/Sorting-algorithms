#include "Constants.h"
#define SC_INCLUDE_FX
#include "systemc.h"

SC_MODULE(RadixSort)
{
private:
    sc_uint<DATA_TYPE> array1[ARRAY_SIZE];
	sc_uint<DATA_TYPE> array2[ARRAY_SIZE];

public:
	sc_in<bool>	clk;
	sc_fifo_in    < sc_uint<DATA_TYPE> > e;
	sc_fifo_out   < sc_uint<DATA_TYPE> > s;

	SC_CTOR(RadixSort)
	{
		SC_CTHREAD(do_sort, clk);
	}

  void do_sort();

 };