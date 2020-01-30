#include <stdio.h>
#include "xil_printf.h"
#include "xaxidma.h"
#include "sleep.h"
#include "xtime_l.h"
#include "xil_types.h"

//#include "platform.h"
#include "axilib/axilib.h"
#include "sorters/splitter.h"

//
// Variable Definitions
//

//#define NB_DATA (64 * MAX_PKT_LEN / 4)
#define NB_DATA (1<<16)
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
		TX[i] = rand();
	}

//#define SPLITTING
#ifdef SPLITTING

#define BLOCK_SIZE (1<<5)
#define NB_MEDIANS (NB_DATA/BLOCK_SIZE - 1)
	xil_printf("Splitting: %d medians\r\n", NB_MEDIANS);
	unsigned int medians[NB_MEDIANS];
	unsigned int imedians[NB_MEDIANS];
	for (int i = 0; i < NB_MEDIANS; i++) {
		medians[0] = 0;
		imedians[i] = (i+1)*(NB_DATA/(NB_MEDIANS+1));
	}

#endif

	XTime tstart, tend;
	XTime_GetTime(&tstart);

//#define CPU_PART
#ifdef CPU_PART
	sort_recur(TX, 0, NB_DATA, medians, imedians, NB_MEDIANS);
#endif

#define FPGA_PART
#ifdef FPGA_PART
	// Send data
	Status = AxiSendData(&AxiDma, TX, NB_DATA*sizeof(uint32_t));
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	// Read data
	Status = AxiReadData(&AxiDma, RX, NB_DATA*sizeof(uint32_t));
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
#endif

	XTime_GetTime(&tend);

	int e = 0;
	for (int i = 1; i < NB_DATA; i++) {
		if (RX[i] < RX[i-1]) {
			e++;
			//xil_printf("%.2d\t\t%.3x\t\t%.3x\r\n", i, RX[i], RX[i-1]);
		}
	}
	for (int i = 0; i < 1<<5<<2; i++) {
		xil_printf("%04d\t\t%08x\t\t%08x\r\n", i, TX[i], RX[i]);
	}


	printf("%d errors\r\n", e);
	int64_t usdt = (tend-tstart) / (COUNTS_PER_SECOND/1000000);
	printf("Run took %llu us\r\n", usdt);

	xil_printf("--- Exiting main() --- \r\n");
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	return XST_SUCCESS;

}
