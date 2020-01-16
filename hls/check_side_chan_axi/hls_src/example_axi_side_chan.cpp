#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

typedef ap_axiu<32, 1, 1, 1> AXI_VALUE;
typedef hls::stream<AXI_VALUE> AXI_STREAM;

#define NB_BENCHED_DATA 32


void HLS_radix(AXI_STREAM& S_AXIS, AXI_STREAM& M_AXIS) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=S_AXIS
#pragma HLS INTERFACE axis port=M_AXIS

	unsigned int tab[NB_BENCHED_DATA] = {0};
	int i;

	for (i = 0; i < NB_BENCHED_DATA; i++) {
		AXI_VALUE val = S_AXIS.read();
		tab[i] = val.data;
	}

	for (i = 0; i < NB_BENCHED_DATA; i++) {
		AXI_VALUE val;
		val.data = tab[i];
		M_AXIS.write(val);
	}

	return;
}


int main() {

	printf("\r\n%s %s\r\nHLS simulation\r\n", __DATE__, __TIME__);

	unsigned int i;
	AXI_STREAM AXIS_S2MM;
	AXI_STREAM AXIS_MM2S;


//	  int i;
//
//	  for(i = 0; i < 50; i++){
//	    B[i].data = A[i].data.to_int() + 5;
//	    B[i].keep = A[i].keep;
//	    B[i].strb = A[i].strb;
//	    B[i].user = A[i].user;
//	    B[i].last = A[i].last;
//	    B[i].id = A[i].id;
//	    B[i].dest = A[i].dest;
//	  }

	printf("Data sent\n");
	for (i = NB_BENCHED_DATA ; i > 0 ; i--) {
		AXI_VALUE val;
		val.data = i;
		AXIS_MM2S.write(val);
		printf("%d\t",i);
	}

	HLS_radix(AXIS_MM2S, AXIS_S2MM);

	printf("\nData received\n");
	unsigned int tmp[NB_BENCHED_DATA];
	for (i = 0; i < NB_BENCHED_DATA; i++) {
		AXI_VALUE val = AXIS_S2MM.read();
		tmp[i] = val.data;
		printf("%u\t", tmp[i]);
	}

	for (i = 0; i < NB_BENCHED_DATA; i++) {
		if(tmp[i+1]<tmp[i])
			printf("C'est un non");
	}

	return 0;
}
