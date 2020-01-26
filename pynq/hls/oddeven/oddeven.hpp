#ifndef ODDEVEN_HPP
#define ODDEVEN_HPP

#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

typedef ap_axiu<32, 1, 1, 1> AXI_VALUE;
typedef hls::stream<AXI_VALUE> AXI_STREAM;

#define SIZE (1<<16)

inline void oddeven_sort(unsigned int* data);
void HLS_oddeven(AXI_STREAM* S_AXIS, AXI_STREAM* M_AXIS);
int main_oddeven();

#endif
