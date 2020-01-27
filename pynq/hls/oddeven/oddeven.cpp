#ifndef ODDEVEN_CPP
#define ODDEVEN_CPP

#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

#include "oddeven.hpp"

inline void swapcmp(unsigned int* a, unsigned int* b) {
	if (*a > *b) {
		unsigned int buf = *b;
		*b = *a;
		*a = buf;
	}
}

inline void oddeven_sort(unsigned int* data) {
	unsigned int i;
	unsigned int j;
	for (i = 0; i < SIZE; i++) {
#pragma HLS DEPENDENCE variable=data inter true
		unsigned int parity = i%2;
		for (j = parity; j < SIZE-1; j+=2) {
#pragma HLS DEPENDENCE variable=data inter false
#pragma HLS UNROLL factor=384
			swapcmp(&data[j], &data[j+1]);
		}
	}
}

void HLS_oddeven(AXI_STREAM* S_AXIS, AXI_STREAM* M_AXIS) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=S_AXIS
#pragma HLS INTERFACE axis port=M_AXIS

	unsigned int data[SIZE];
	unsigned int i;
	AXI_VALUE val;

	// Read data
	for (i = 0; i < SIZE; i++) {
		val = S_AXIS->read();
		data[i] = val.data;
	}
	val.last = 0;

	// Sort data
	oddeven_sort(data);

	// Write back
	for (i = 0; i < SIZE; i++) {
		val.data = data[i];
		if (i == SIZE-1) val.last = 1;
		M_AXIS->write(val);
	}

	return;
}

int main_oddeven() {
	int i;
	AXI_STREAM AXIS_S2MM;
	AXI_STREAM AXIS_MM2S;
	unsigned int data_o[SIZE];
	unsigned int data_i[SIZE];

	for (i=0; i<SIZE; i++) {
		data_o[i] = rand();
	}

	for (i = 0; i < SIZE; i++) {
		AXI_VALUE val;
		val.data = data_o[i];
		AXIS_MM2S.write(val);
	}

	HLS_oddeven(&AXIS_MM2S, &AXIS_S2MM);

	for (i = 0; i < SIZE; i++) {
		AXI_VALUE val = AXIS_S2MM.read();
		data_i[i] = val.data;
	}


	/*
	for (i = 0; i < SIZE; i++) {
		printf("Index: %4x\tSent: %4x\tData: %4x\r\n",
				i, data_o[i], data_i[i]);
	}
	*/

	unsigned int e = 0;
	for (i = 1; i < SIZE; i++) {
		if (data_i[i] < data_i[i-1]) {
			e++;
			printf("Index: %4x\tSent: %4x\tPrev: %4x\tData: %4x\r\n",
					i, data_o[i], data_i[i-1], data_i[i]);
		}
	}
	printf("%d errors\r\n", e);
	return 0;
}

#endif

