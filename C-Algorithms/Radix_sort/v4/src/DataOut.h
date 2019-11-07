#include "systemc.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

SC_MODULE(DataOut)
{
	sc_fifo_out< sc_uint<DATA_TYPE> > e;

    void do_print();           // process

	SC_CTOR(DataOut)
	{
		SC_THREAD(do_print);
	}

