#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

//#include "fifo/fifo.hpp"
#include "bitonic/bitonic.hpp"
//#include "oddeven/oddeven.hpp"


int main() {

	printf("\r\nHLS simulation: %s %s\r\n", __DATE__, __TIME__);

	main_bitonic();

	printf("End of simulation\r\n\r\n");
	return 0;
}

