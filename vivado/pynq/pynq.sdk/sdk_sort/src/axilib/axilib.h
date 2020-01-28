#ifndef SRC_AXILIB_H_
#define SRC_AXILIB_H_

#include "xaxidma.h"

//
// Device hardware build related constants
//
#define DMA_DEV_ID		XPAR_AXIDMA_0_DEVICE_ID

#ifdef	XPAR_AXI_7SDDR_0_S_AXI_BASEADDR
#define	DDR_BASE_ADDR 	XPAR_AXI_7SDDR_0_S_AXI_BASEADDR
#elif	XPAR_MIG7SERIES_0_BASEADDR
#define	DDR_BASE_ADDR 	XPAR_MIG7SERIES_0_BASEADDR
#elif	XPAR_MIG_0_BASEADDR
#define	DDR_BASE_ADDR 	XPAR_MIG_0_BASEADDR
#elif	XPAR_PSU_DDR_0_S_AXI_BASEADDR
#define	DDR_BASE_ADDR 	XPAR_PSU_DDR_0_S_AXI_BASEADDR
#endif

#ifndef	DDR_BASE_ADDR
#define	MEM_BASE_ADDR	0x01000000
#else
#define	MEM_BASE_ADDR	(DDR_BASE_ADDR + 0x1000000)
#endif

#define TX_BD_SPACE_BASE	(MEM_BASE_ADDR)
#define TX_BD_SPACE_HIGH	(MEM_BASE_ADDR + 0x00000FFF)
#define RX_BD_SPACE_BASE	(MEM_BASE_ADDR + 0x00001000)
#define RX_BD_SPACE_HIGH	(MEM_BASE_ADDR + 0x00001FFF)
#define TX_BUFFER_BASE		(MEM_BASE_ADDR + 0x00100000)
#define RX_BUFFER_BASE		(MEM_BASE_ADDR + 0x00300000)
#define RX_BUFFER_HIGH		(MEM_BASE_ADDR + 0x004FFFFF)

#define MAX_PKT_LEN			0x0200		//0x2000	// In bytes
#define MARK_UNCACHEABLE	0x701

#define TEST_START_VALUE	0x55

//
// Function prototypes
//

#if defined(XPAR_UARTNS550_0_BASEADDR)
static void Uart550_Setup(void);
#endif

int AxiInit(XAxiDma* AxiDmaInstPtr);

int AxiSendDone(XAxiDma* AxiDmaInstPtr);
//int AxiReadyToRead(XAxiDma* AxiDmaInstPtr);

int AxiSendData(XAxiDma* AxiDmaInstPtr, uint32_t* txsrc, size_t size);
int AxiReadData(XAxiDma* AxiDmaInstPtr, uint32_t* rxdst, size_t size);

#endif /* SRC_AXILIB_H_ */
