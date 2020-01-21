#include <stdio.h>
#include <stdlib.h>
#include "radix.h"

#include <ap_axi_sdata.h>
#include <hls_stream.h>

// AXI bus properties
	#define AXI_D		32		// Data bus width in bits
	#define AXI_U		1		// USER width in bits
	#define AXI_TI		1		// ID width in bits
	#define AXI_TD		1		// DEST width in bits
	#define AXI_LAST	1

	typedef ap_axiu<AXI_D, AXI_U, AXI_TI, AXI_TD> AXI_VALUE;
	typedef hls::stream<AXI_VALUE> AXI_STREAM;

// Number of data
	#define NB_BENCHED_DATA	NB_DATA


void HLS_radix(AXI_STREAM& S_AXIS, AXI_STREAM& M_AXIS) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=S_AXIS
#pragma HLS INTERFACE axis port=M_AXIS

	unsigned int tab[NB_BENCHED_DATA] = {0};
	int i;
	AXI_VALUE val;

	while(1){
		for (i = 0; i < NB_BENCHED_DATA; i++)
		{
			val = S_AXIS.read();
			tab[i] = val.data;
		}

		radix_sort_v2(tab, NB_BENCHED_DATA);
		val.last = 0;

		for (i = 0; i < NB_BENCHED_DATA; i++)
		{
			val.data = tab[i];

			if(i == (NB_BENCHED_DATA-1))
				val.last = 1;

			M_AXIS.write(val);
		}
	}

	return;
}


int main() {

	printf("\r\n%s %s\r\nHLS simulation\r\n", __DATE__, __TIME__);

	unsigned int i;
	AXI_STREAM AXIS_S2MM;
	AXI_STREAM AXIS_MM2S;

	printf("Data sent\n");
	for (i = NB_BENCHED_DATA ; i > 0 ; i--) {
		AXI_VALUE val;
		val.data = i;
		AXIS_MM2S.write(val);
		//printf("%d\t",i);
	}

	HLS_radix(AXIS_MM2S, AXIS_S2MM);

	printf("\nData received\n");
	unsigned int tmp[NB_BENCHED_DATA];
	for (i = 0; i < NB_BENCHED_DATA; i++) {
		AXI_VALUE val = AXIS_S2MM.read();
		tmp[i] = val.data;
		//printf("%u\t", tmp[i]);
	}
	for (i = 0; i < NB_BENCHED_DATA; i++) {
		if(tmp[i]>tmp[i+1])
			printf("C'est un non");
	}

	return 0;
}


