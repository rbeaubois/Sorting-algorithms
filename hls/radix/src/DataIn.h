#include "Constants.h"
#define SC_INCLUDE_FX
#include "systemc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>


SC_MODULE(DataIn)
{
	sc_in<bool> clk;
	sc_fifo_out< sc_uint<DATA_TYPE> > s;

	SC_CTOR(DataIn)
	{
		SC_CTHREAD(do_gen, clk);
	}

    void do_gen();           // process

};
