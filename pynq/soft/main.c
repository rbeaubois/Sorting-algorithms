#include <stdio.h>
//#include "platform.h"
#include "xil_printf.h"

#include "xaxidma.h"

#include "axilib/axilib.h"

//
// Variable Definitions
//

XAxiDma AxiDma;
uint32_t* TX = ((uint32_t*) TX_BUFFER_BASE + 50);
uint32_t* RX = ((uint32_t*) RX_BUFFER_BASE);

int main() {

	xil_printf("\r\nRun at: %s %s\r\n", __DATE__, __TIME__);
	xil_printf("--- Entering main() --- \r\n");

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

	for (int i = 0; i < 64; i++) {
		TX[i] = i;
	}

	// Send a packet
	Status = AxiSendData(&AxiDma, TX, 64);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	// Read a packet
	Status = AxiReadData(&AxiDma, RX, 64);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	for (int i = 0; i < 64; i++) {
		xil_printf("%.2d\t\t%.3x\t\t%.3x\r\n", i, TX[i], RX[i]);
	}

	//xil_printf("Successfully ran AXI DMA SG Polling Example\r\n");
	xil_printf("--- Exiting main() --- \r\n");
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	return XST_SUCCESS;

}
