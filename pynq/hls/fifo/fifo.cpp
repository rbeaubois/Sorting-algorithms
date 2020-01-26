#ifndef FIFO_CPP
#define FIFO_CPP

#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

#include "fifo.hpp"

void HLS_fifo(AXI_STREAM* S_AXIS, AXI_STREAM* M_AXIS) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=S_AXIS
#pragma HLS INTERFACE axis port=M_AXIS

	int i;
	AXI_VALUE val;

	for (i = 0; i < SIZE; i++) {
		val = S_AXIS->read();
		val.data += 1;
		M_AXIS->write(val);
	}

	return;
}

int main_fifo() {
	int i;
	AXI_STREAM AXIS_S2MM;
	AXI_STREAM AXIS_MM2S;
	unsigned int data[SIZE];

	for (i = 0; i < SIZE; i++) {
		AXI_VALUE val;
		val.data = i;
		AXIS_MM2S.write(val);
	}

	HLS_fifo(&AXIS_MM2S, &AXIS_S2MM);

	for (i = 0; i < SIZE; i++) {
		AXI_VALUE val = AXIS_S2MM.read();
		data[i] = val.data;
	}

	unsigned int e = 0;
	for (i = 0; i < SIZE; i++) {
		if (data[i] != i) {
			e++;
			//printf("Index: %4x\tSent: %4x\tRecv: %4x\r\n", i, i, data[i]);
		}
	}
	printf("%d errors\r\n", e);

	return 0;
}

#endif

