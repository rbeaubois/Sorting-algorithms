#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

#define SIZE (1<<16)

typedef ap_axiu<32, 1, 1, 1> AXI_VALUE;
typedef hls::stream<AXI_VALUE> AXI_STREAM;

void HLS_fifo(AXI_STREAM* S_AXIS, AXI_STREAM* M_AXIS);
int main_fifo();
