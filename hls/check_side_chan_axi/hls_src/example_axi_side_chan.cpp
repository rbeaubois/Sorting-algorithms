#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

typedef ap_axiu<32, 1, 1, 1> AXI_VALUE;
typedef hls::stream<AXI_VALUE> AXI_STREAM;

#define NB_BENCHED_DATA 64


void HLS_accel(AXI_STREAM& S_AXIS, AXI_STREAM& M_AXIS) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=S_AXIS
#pragma HLS INTERFACE axis port=M_AXIS

	unsigned int tab[NB_BENCHED_DATA] = {0};
	int i;

	AXI_VALUE val[NB_BENCHED_DATA];

	for (i = 0; i < NB_BENCHED_DATA; i++) {
//		AXI_VALUE val = S_AXIS.read();
//		tab[i] = val.data;
		val[i] = S_AXIS.read();
		tab[i] = val[i].data;
	}

	for (i = 0; i < NB_BENCHED_DATA; i++) {
		tab[i] = tab[i]*2;
	}

	for (i = 0; i < NB_BENCHED_DATA; i++) {
//		AXI_VALUE val;
//		val.data = tab[i];
//		M_AXIS.write(val);
		val[i].data = tab[i];
		M_AXIS.write(val[i]);
	}

	return;
}


int main() {

	printf("\r\n%s %s\r\nHLS simulation\r\n", __DATE__, __TIME__);

	unsigned int i;
	AXI_STREAM AXIS_S2MM;
	AXI_STREAM AXIS_MM2S;

	unsigned int tmpd;
	unsigned int keep;
	unsigned int strb;
	unsigned int user;
	unsigned int last;
	unsigned int id;
	unsigned int dest;

	printf("Data sent\n");
	for (i = NB_BENCHED_DATA ; i > 0 ; i--) {
		AXI_VALUE val;
		val.data = i;
		AXIS_MM2S.write(val);

		tmpd 	= val.data;
		keep 	= val.keep;
		strb 	= val.strb;
		user 	= val.user;
		last 	= val.last;
		dest 	= val.dest;
		id 		= val.id;

		printf("\tdata : %u\n",		tmpd);
		printf("\tkeep : %u\n",		keep);
		printf("\tstrb : %u\n",		strb);
		printf("\tuser : %u\n",		user);
		printf("\tlast : %u\n",		last);
		printf("\tid   : %u\n",		id);
		printf("\tdest : %u\n\n",	dest);
	}

	HLS_accel(AXIS_MM2S, AXIS_S2MM);

	printf("\nData received\n");
	for (i = 0; i < NB_BENCHED_DATA; i++) {
		AXI_VALUE val = AXIS_S2MM.read();
		
		tmpd 	= val.data;
		keep 	= val.keep;
		strb 	= val.strb;
		user 	= val.user;
		last 	= val.last;
		dest 	= val.dest;
		id 		= val.id;

		printf("\tdata : %u\n",		tmpd);
		printf("\tkeep : %u\n",		keep);
		printf("\tstrb : %u\n",		strb);
		printf("\tuser : %u\n",		user);
		printf("\tlast : %u\n",		last);
		printf("\tid   : %u\n",		id);
		printf("\tdest : %u\n\n",	dest);
	}

	return 0;
}
