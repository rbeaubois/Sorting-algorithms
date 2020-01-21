#include <stdio.h>
#include <stdlib.h>

#include <ap_axi_sdata.h>
#include <hls_stream.h>

#include "fifo/fifo.hpp"
//#include "bitonic/bitonic.hpp"


int main() {

	printf("\r\n%s %s\r\nHLS simulation\r\n", __DATE__, __TIME__);

	main_fifo();

	printf("End of simulation\r\n");
	return 0;
}

