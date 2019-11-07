#define SC_INCLUDE_FX
#include "systemc.h"

// Number of elements
#define ARRAY_SIZE      64000
#define ADDR_SIZE       16

// Type of data
#define U_INT           32
#define DATA_TYPE       U_INT

// Masks
#define M_NIBBLE        0x0000000F
#define M_BYTE          0x000000FF
#define MASK            M_BYTE

// Number of possible values with mask
#define V_NIBBLE        16
#define V_BYTE          256
#define NB_VALUES       V_BYTE

// Number of bits for the mask
#define B_NIBBLE        4
#define B_BYTE          8
#define SHIFT           B_BYTE     

SC_MODULE(Radix_sort)
{
public:
  sc_in         <bool>                    clk;
  sc_fifo_in    < sc_uint<DATA_TYPE> >    i_data;
  sc_fifo_out   < sc_uint<DATA_TYPE> >    o_data;

	SC_CTOR(Radix_sort)
	{
		SC_CTHREAD(do_sort, clk);
	}

    void do_sort();
 };
