#include <stdio.h>
#include "xil_printf.h"
#include "xaxidma.h"
#include "sleep.h"
#include "xtime_l.h"

//#include "platform.h"
#include "axilib/axilib.h"

//
// Variable Definitions
//

#define NB_DATA (64 * MAX_PKT_LEN / 4)
XAxiDma AxiDma;
uint32_t* TX = ((uint32_t*) TX_BUFFER_BASE);
uint32_t* RX = ((uint32_t*) RX_BUFFER_BASE);

int main() {

	xil_printf("\r\nRun at: %s %s\r\n", __DATE__, __TIME__);
	xil_printf("--- Entering main() --- \r\n");
	xil_printf("NB_DATA: %d\r\n", NB_DATA);

	int Status;
	XAxiDma_Config *Config;

	//Xil_ICacheDisable();
	//Xil_DCacheDisable();

#ifdef __aarch64__
	Xil_SetTlbAttributes(TX_BD_SPACE_BASE, MARK_UNCACHEABLE);
	Xil_SetTlbAttributes(RX_BD_SPACE_BASE, MARK_UNCACHEABLE);
#endif

	Config = XAxiDma_LookupConfig(DMA_DEV_ID);
	if (!Config) {
		xil_printf("No config found for %d\r\n", DMA_DEV_ID);

		return XST_FAILURE;
	}

	// Initialize DMA engine
	Status = XAxiDma_CfgInitialize(&AxiDma, Config);
	if (Status != XST_SUCCESS) {
		xil_printf("Initialization failed %d\r\n", Status);
		return XST_FAILURE;
	}

	if (!XAxiDma_HasSg(&AxiDma)) {
		xil_printf("Device configured as Simple mode \r\n");

		return XST_FAILURE;
	}

	Status = AxiInit(&AxiDma);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	for (int i = 0; i < NB_DATA; i++) {
		TX[i] = i;
	}

	XTime tstart, tend;
	XTime_GetTime(&tstart);
	// Send a packet
	Status = AxiSendData(&AxiDma, TX, NB_DATA*sizeof(uint32_t));
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	//usleep(100000);

	// Read a packet
	Status = AxiReadData(&AxiDma, RX, NB_DATA*sizeof(uint32_t));
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	XTime_GetTime(&tend);

	int e = 0;
	for (int i = 0; i < NB_DATA; i++) {
		if (RX[i] != TX[i] + 1) e++;
			//xil_printf("%.2d\t\t%.3x\t\t%.3x\r\n", i, TX[i], RX[i]);
	}

	printf("%d errors\r\n", e);
	int64_t usdt = (tend-tstart) / (COUNTS_PER_SECOND/1000000);
	printf("Run took %llu us\r\n", usdt);

	//xil_printf("Successfully ran AXI DMA SG Polling Example\r\n");
	xil_printf("--- Exiting main() --- \r\n");
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	return XST_SUCCESS;

}
