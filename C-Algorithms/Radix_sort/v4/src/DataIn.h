#include "RadixSort.h"
#include "systemc.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>


SC_MODULE(DataIn)
{
	sc_fifo_out< sc_uint<DATA_TYPE> > s;

	SC_CTOR(DataIn)
	{
		SC_THREAD(do_gen);
	}

    void do_gen();           // process

};