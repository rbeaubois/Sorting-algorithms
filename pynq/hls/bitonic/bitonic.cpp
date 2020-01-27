#ifndef BITONIC_CPP
#define BITONIC_CPP

#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

#include "bitonic.hpp"

inline void swapcmp(unsigned int* a, unsigned int* b) {
	if (*a > *b) {
		unsigned int buf = *b;
		*b = *a;
		*a = buf;
	}
}

inline void bitonic_sort(unsigned int* data) {
	int i;
	for (i = 0; i < STEP; i++) { // Etapes successives du tri
#pragma HLS DEPENDENCE variable=data inter true
		unsigned int si = 1 << i;
		unsigned int gs = si << 1;
// Sous etape 1, dont l'ordre de comparaison est different des autres
// Boucle sur tous les sous groupe de la sous etape 1
	for (unsigned int k = 0; k < SIZE; k += gs) {
#pragma HLS DEPENDENCE variable=data inter false
#pragma HLS UNROLL factor=8
// Boucle sur tous les elements du sous groupe
			for (unsigned int l = 0; l < si; l++) {
#pragma HLS DEPENDENCE variable=data inter false
#pragma HLS UNROLL factor=16
				swapcmp(&data[k+l], &data[k-l+gs-1]);
			}
		}
// Boucle sur toutes les sous etapes
		for (unsigned int j = 1; j <= i; j++) {
#pragma HLS DEPENDENCE variable=data inter true
			gs >>= 1;
			si >>= 1;
// Boucle sur tous les sous groupe de la sous etape j
			for (unsigned int k = 0; k < SIZE; k += gs) {
#pragma HLS DEPENDENCE variable=data inter false
#pragma HLS UNROLL factor=8
// Boucle sur tous les elements du sous groupe
				for (unsigned int l = 0; l < si; l++) {
#pragma HLS DEPENDENCE variable=data inter false
#pragma HLS UNROLL factor=16
					swapcmp(&data[k+l], &data[k+l+si]);
				}
			}
		}
	}
}

void HLS_bitonic(AXI_STREAM* S_AXIS, AXI_STREAM* M_AXIS) {
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
	bitonic_sort(data);

	// Write back
	for (i = 0; i < SIZE; i++) {
		val.data = data[i];
		if (i == SIZE-1) val.last = 1;
		M_AXIS->write(val);
	}

	return;
}

int main_bitonic() {
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

	HLS_bitonic(&AXIS_MM2S, &AXIS_S2MM);

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
