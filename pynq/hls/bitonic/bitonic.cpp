#ifndef BITONIC_CPP
#define BITONIC_CPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

#include "bitonic.hpp"

#define SPLITTING
#ifdef SPLITTING
#include "../splitter.hpp"
#endif

inline void swapcmp(unsigned int* a, unsigned int* b) {
	if (*a > *b) {
		unsigned int buf = *b;
		*b = *a;
		*a = buf;
	}
}

inline void bitonic_sort(unsigned int* subdata) {
	unsigned int i;
	for (i = 0; i < STEP; i++) {
		unsigned int si = 1 << i;
		unsigned int gs = si << 1;
		for (unsigned int k = 0; k < MSIZE; k += gs) {
#pragma HLS DEPENDENCE variable=subdata inter false
			for (unsigned int l = 0; l < si; l++) {
#pragma HLS DEPENDENCE variable=subdata inter false
				swapcmp(&subdata[k+l], &subdata[k-l+gs-1]);
			}
		}
		for (unsigned int j = 1; j <= i; j++) {
			gs >>= 1;
			si >>= 1;
			for (unsigned int k = 0; k < MSIZE; k += gs) {
#pragma HLS DEPENDENCE variable=subdata inter false
				for (unsigned int l = 0; l < si; l++) {
#pragma HLS DEPENDENCE variable=subdata inter false
					swapcmp(&subdata[k+l], &subdata[k+l+si]);
				}
			}
		}
	}
}

void HLS_bitonic(AXI_STREAM* S_AXIS, AXI_STREAM* M_AXIS) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=S_AXIS
#pragma HLS INTERFACE axis port=M_AXIS

	unsigned int i;

	for (i = 0; i < TSIZE/MSIZE; i++) {
#pragma HLS PIPELINE

		unsigned int j;
		unsigned int data[MSIZE];
		#pragma HLS ARRAY_PARTITION variable=data complete dim=1
		AXI_VALUE val;

		// Read data
		for (j = 0; j < MSIZE; j++) {
			val = S_AXIS->read();
			data[j] = val.data;
		}
		val.last = 0;

		// Sort data
		bitonic_sort(data);

		// Write back
		for (j = 0; j < MSIZE; j++) {
			val.data = data[j];
			if (i*MSIZE + j == TSIZE-1) val.last = 1;
			M_AXIS->write(val);
		}

	}

	return;
}

int main_bitonic() {
	int i;
	AXI_STREAM AXIS_S2MM;
	AXI_STREAM AXIS_MM2S;
	unsigned int data_o[TSIZE];
	unsigned int data_i[TSIZE];
	unsigned int e;

	srand(time(0));

	for (i=0; i<TSIZE; i++) {
		data_o[i] = rand();
	}

#ifdef SPLITTING

#define NB_MEDIANS (TSIZE/MSIZE - 1)
	printf("Splitting: %d medians (%d blocks)\r\n", NB_MEDIANS, TSIZE/MSIZE);
	unsigned int medians[NB_MEDIANS];
	unsigned int imedians[NB_MEDIANS];
	for (int i = 0; i < NB_MEDIANS; i++) {
		medians[0] = 0;
		imedians[i] = (i+1)*(TSIZE/(NB_MEDIANS+1));
		printf("#%d median index: %d\r\n", i, imedians[i]);
	}
	sort_recur(data_o, 0, TSIZE, medians, imedians, NB_MEDIANS);

	e = 0;
	for (i = 1; i < TSIZE; i++) {
		if (data_o[i] < data_o[i-1]) {
			e++;
		}
	}
	printf("%d unsorted data after splitting\r\n", e);

#endif

	for (i = 0; i < TSIZE; i++) {
		AXI_VALUE val;
		val.data = data_o[i];
		AXIS_MM2S.write(val);
	}

	HLS_bitonic(&AXIS_MM2S, &AXIS_S2MM);

	for (i = 0; i < TSIZE; i++) {
		AXI_VALUE val = AXIS_S2MM.read();
		data_i[i] = val.data;
	}

// /*
	for (i = 0; i < TSIZE; i++) {
		printf("Index: %.4d\tSent: %.8x\tData: %.8x\r\n",
				i, data_o[i], data_i[i]);
	}
// */

	e = 0;
	for (i = 1; i < TSIZE; i++) {
		if (data_i[i] < data_i[i-1]) {
			e++;
			printf("Index: %.4d\tSent: %.8x\tPrev: %4x\tData: %.8x\r\n",
					i, data_o[i], data_i[i-1], data_i[i]);
		}
	}
	printf("Final: %d errors\r\n", e);

	return 0;
}

#endif


/*
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
*/
