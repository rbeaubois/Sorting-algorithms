#include "Constants.h"
#define SC_INCLUDE_FX
#include "systemc.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

SC_MODULE(DataOut)
{
	sc_fifo_in < sc_uint<DATA_TYPE> > e;

	SC_CTOR(DataOut)
	{
		SC_THREAD(do_print);
	}

	void do_print();           // process

};

