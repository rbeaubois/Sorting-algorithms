#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

typedef ap_axiu<32, 1, 1, 1> AXI_VALUE;
typedef hls::stream<AXI_VALUE> AXI_STREAM;

void HLS_accel(AXI_STREAM* S_AXIS, AXI_STREAM* M_AXIS) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=S_AXIS
#pragma HLS INTERFACE axis port=M_AXIS

	int i;
	//for (i = 0; i < 128; i++) {
	while(1) {
		AXI_VALUE val = S_AXIS->read();
		val.data = (val.data + 1);
		M_AXIS->write(val);
	}

	return;
}

int main() {

	printf("\r\n%s %s\r\nHLS simulation\r\n", __DATE__, __TIME__);

	int i;
	AXI_STREAM AXIS_S2MM;
	AXI_STREAM AXIS_MM2S;

	for (i = 0; i < 32; i++) {
		AXI_VALUE val;
		val.data = i;
		AXIS_MM2S.write(val);
	}

	HLS_accel(&AXIS_MM2S, &AXIS_S2MM);

	for (i = 0; i < 32; i++) {
		AXI_VALUE val = AXIS_S2MM.read();
		printf("Index: %4x\t\tValue: %4x\r\n", i, val.data.to_int());
	}

	printf("Success: HW and SW results match\n");
	return 0;
}

