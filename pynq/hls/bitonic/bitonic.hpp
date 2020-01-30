#ifndef BITONIC_HPP
#define BITONIC_HPP

#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

typedef ap_axiu<32, 1, 1, 1> AXI_VALUE;
typedef hls::stream<AXI_VALUE> AXI_STREAM;

#define TSIZE (1<<4)
#define STEP 2
#define MSIZE (1<<STEP)


inline void bitonic_sort(unsigned int* data);
void HLS_bitonic(AXI_STREAM* S_AXIS, AXI_STREAM* M_AXIS);
int main_bitonic();

#endif
