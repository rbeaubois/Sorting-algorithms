#include "axilib.h"

#include "xaxidma.h"

int AxiInit(XAxiDma* AxiDmaInstPtr) {

	//Common variables
	uint32_t BdCount;
	XAxiDma_Bd BdTemplate;
	int Delay = 0;
	int Coalesce = 1;
	int Status;

	// RX Variables
	XAxiDma_BdRing *RxRingPtr;
	XAxiDma_Bd *BdPtr;
	XAxiDma_Bd *BdCurPtr;
	uint32_t FreeBdCount;
	UINTPTR RxBufferPtr;
	int Index;

	// TX Variables
	XAxiDma_BdRing *TxRingPtr;

	/*
	 * RX config
	 */

	RxRingPtr = XAxiDma_GetRxRing(AxiDmaInstPtr);

	// Disable all RX interrupts before RxBD space setup
	XAxiDma_BdRingIntDisable(RxRingPtr, XAXIDMA_IRQ_ALL_MASK);

	// Set delay and coalescing
	XAxiDma_BdRingSetCoalesce(RxRingPtr, Coalesce, Delay);

	// Setup Rx BD space
	BdCount = XAxiDma_BdRingCntCalc(XAXIDMA_BD_MINIMUM_ALIGNMENT,
			RX_BD_SPACE_HIGH - RX_BD_SPACE_BASE + 1);
	Status = XAxiDma_BdRingCreate(RxRingPtr, RX_BD_SPACE_BASE,
	RX_BD_SPACE_BASE, XAXIDMA_BD_MINIMUM_ALIGNMENT, BdCount);
	if (Status != XST_SUCCESS) {
		xil_printf("RX create BD ring failed %d\r\n", Status);
		return XST_FAILURE;
	}

	// Setup an all-zero BD as the template for the Rx channel.
	XAxiDma_BdClear(&BdTemplate);
	Status = XAxiDma_BdRingClone(RxRingPtr, &BdTemplate);
	if (Status != XST_SUCCESS) {
		xil_printf("RX clone BD failed %d\r\n", Status);
		return XST_FAILURE;
	}

	// Attach buffers to RxBD ring so we are ready to receive packets
	FreeBdCount = XAxiDma_BdRingGetFreeCnt(RxRingPtr);
	Status = XAxiDma_BdRingAlloc(RxRingPtr, FreeBdCount, &BdPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("RX alloc BD failed %d\r\n", Status);
		return XST_FAILURE;
	}

	BdCurPtr = BdPtr;
	RxBufferPtr = RX_BUFFER_BASE;
	for (Index = 0; Index < FreeBdCount; Index++) {
		// Map buffers to addresses
		Status = XAxiDma_BdSetBufAddr(BdCurPtr, RxBufferPtr);
		if (Status != XST_SUCCESS) {
			xil_printf("Set buffer addr %x on BD %x failed %d\r\n",
					(unsigned int) RxBufferPtr, (uintptr_t) BdCurPtr, Status);
			return XST_FAILURE;
		}
		// Set length of BDs
		Status = XAxiDma_BdSetLength(BdCurPtr, MAX_PKT_LEN,
				RxRingPtr->MaxTransferLen);
		if (Status != XST_SUCCESS) {
			xil_printf("Rx set length %d on BD %x failed %d\r\n",
			MAX_PKT_LEN, (UINTPTR) BdCurPtr, Status);
			return XST_FAILURE;
		}

		// Disable all control for RX BDs
		XAxiDma_BdSetCtrl(BdCurPtr, 0);

		// Set BD id
		XAxiDma_BdSetId(BdCurPtr, RxBufferPtr);

		RxBufferPtr += MAX_PKT_LEN;
		BdCurPtr = (XAxiDma_Bd*) XAxiDma_BdRingNext(RxRingPtr, BdCurPtr);
	}

	// Clear the receive buffer
	memset((void*) RX_BUFFER_BASE, 0, MAX_PKT_LEN);

	// Return processed BDs to RX channel
	Status = XAxiDma_BdRingToHw(RxRingPtr, FreeBdCount, BdPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("RX submit hw failed %d\r\n", Status);
		return XST_FAILURE;
	}

	// Start RX DMA channel
	Status = XAxiDma_BdRingStart(RxRingPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("RX start hw failed %d\r\n", Status);
		return XST_FAILURE;
	}

	/*
	 * TX config
	 */

	TxRingPtr = XAxiDma_GetTxRing(AxiDmaInstPtr);

	// Disable all TX interrupts before TxBD space setup
	XAxiDma_BdRingIntDisable(TxRingPtr, XAXIDMA_IRQ_ALL_MASK);

	// Set TX delay and coalesce
	XAxiDma_BdRingSetCoalesce(TxRingPtr, Coalesce, Delay);

	// Setup TxBD space
	BdCount = XAxiDma_BdRingCntCalc(XAXIDMA_BD_MINIMUM_ALIGNMENT,
			TX_BD_SPACE_HIGH - TX_BD_SPACE_BASE + 1);
	Status = XAxiDma_BdRingCreate(TxRingPtr, TX_BD_SPACE_BASE,
	TX_BD_SPACE_BASE, XAXIDMA_BD_MINIMUM_ALIGNMENT, BdCount);
	if (Status != XST_SUCCESS) {
		xil_printf("Failed create BD ring in txsetup\r\n");
		return XST_FAILURE;
	}

	// We create an all-zero BD as the template.
	XAxiDma_BdClear(&BdTemplate);
	Status = XAxiDma_BdRingClone(TxRingPtr, &BdTemplate);
	if (Status != XST_SUCCESS) {
		xil_printf("Failed bdring clone in txsetup %d\r\n", Status);
		return XST_FAILURE;
	}

	// Start the TX channel
	Status = XAxiDma_BdRingStart(TxRingPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("Failed start bdring txsetup %d\r\n", Status);
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

int AxiSendData(XAxiDma* AxiDmaInstPtr, uint32_t* txsrc, uint32_t nb) {

	XAxiDma_BdRing *TxRingPtr;
	XAxiDma_Bd *BdPtr;
	int Status;

	TxRingPtr = XAxiDma_GetTxRing(AxiDmaInstPtr);

	// Flush the SrcBuffer before the DMA transfer
	Xil_DCacheFlushRange((uintptr_t) txsrc, nb * sizeof(uint32_t));
#ifdef __aarch64__
	Xil_DCacheFlushRange((uintptr_t)txsrc, nb*sizeof(uint32_t));
#endif

	// Allocate a BD
	Status = XAxiDma_BdRingAlloc(TxRingPtr, 1, &BdPtr);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	// Set up the BD using the information of the packet to transmit
	Status = XAxiDma_BdSetBufAddr(BdPtr, (uintptr_t) txsrc);
	if (Status != XST_SUCCESS) {
		xil_printf("Tx set buffer addr %x on BD %x failed %d\r\n",
				(uint32_t*) txsrc, (uint32_t*) BdPtr, Status);
		return XST_FAILURE;
	}

	Status = XAxiDma_BdSetLength(BdPtr, nb * sizeof(uint32_t),
			TxRingPtr->MaxTransferLen);
	if (Status != XST_SUCCESS) {
		xil_printf("Tx set length %d on BD %x failed %d\r\n",
		MAX_PKT_LEN, (uint32_t) BdPtr, Status);
		return XST_FAILURE;
	}

#if (XPAR_AXIDMA_0_SG_INCLUDE_STSCNTRL_STRM == 1)
	Status = XAxiDma_BdSetAppWord(BdPtr, XAXIDMA_LAST_APPWORD,
			MAX_PKT_LEN);
	// If Set app length failed, it is not fatal
	if (Status != XST_SUCCESS) {
		xil_printf("Set app word failed with %d\r\n", Status);
	}
#endif

	// For single packet, both SOF and EOF are to be set
	XAxiDma_BdSetCtrl(BdPtr,
	XAXIDMA_BD_CTRL_TXEOF_MASK | XAXIDMA_BD_CTRL_TXSOF_MASK);

	XAxiDma_BdSetId(BdPtr, (uintptr_t )txsrc);

	// Give the BD to DMA to kick off the transmission
	Status = XAxiDma_BdRingToHw(TxRingPtr, 1, BdPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("to hw failed %d\r\n", Status);
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

int AxiReadData(XAxiDma* AxiDmaInstPtr, uint32_t* rxdst, uint32_t nb) {

	XAxiDma_BdRing *TxRingPtr;
	XAxiDma_BdRing *RxRingPtr;
	XAxiDma_Bd *BdPtr;
	int ProcessedBdCount;
	int FreeBdCount;
	int Status;

	TxRingPtr = XAxiDma_GetTxRing(AxiDmaInstPtr);
	RxRingPtr = XAxiDma_GetRxRing(AxiDmaInstPtr);

	// Wait until the one BD TX transaction is done
	while ((ProcessedBdCount = XAxiDma_BdRingFromHw(TxRingPtr,
	XAXIDMA_ALL_BDS, &BdPtr)) == 0) {
	}

	// Free all processed TX BDs for future transmission
	Status = XAxiDma_BdRingFree(TxRingPtr, ProcessedBdCount, BdPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("Failed to free %d tx BDs %d\r\n", ProcessedBdCount, Status);
		return XST_FAILURE;
	}

	// Wait until the data has been received by the Rx channel
	while ((ProcessedBdCount = XAxiDma_BdRingFromHw(RxRingPtr,
	XAXIDMA_ALL_BDS, &BdPtr)) == 0) {
	}

	// Invalidate the DestBuffer before receiving the data
#ifndef __aarch64__
	Xil_DCacheInvalidateRange((UINTPTR) rxdst, nb * sizeof(uint32_t));
#endif

	// Free all processed RX BDs for future transmission
	Status = XAxiDma_BdRingFree(RxRingPtr, ProcessedBdCount, BdPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("Failed to free %d rx BDs %d\r\n", ProcessedBdCount, Status);
		return XST_FAILURE;
	}

	// Return processed BDs to RX channel
	FreeBdCount = XAxiDma_BdRingGetFreeCnt(RxRingPtr);
	Status = XAxiDma_BdRingAlloc(RxRingPtr, FreeBdCount, &BdPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("bd alloc failed\r\n");
		return XST_FAILURE;
	}
	Status = XAxiDma_BdRingToHw(RxRingPtr, FreeBdCount, BdPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("Submit %d rx BDs failed %d\r\n", FreeBdCount, Status);
		return XST_FAILURE;
	}

	return XST_SUCCESS;

}

