#include <stdio.h>
#include "xil_printf.h"
#include "xaxidma.h"
#include "sleep.h"
#include "xtime_l.h"
//#include "tim/tim.h"
//#include "bubble/bubble.h"
#include "trident/trident.h"

#include "platform.h"

#define NB_DATA 		65536
#define MAX_DATA_POWER	16		// 2^16 = 65536
#define AVERAGING   	25		// Number of runs for a fixed number of data
#define NB_SETS			10		// Number of data sets to run

// Generate n random datas of type unsigned int
void randomize(unsigned int* data, int n){

    for(int i = 0; i < n; i++) {
        data[i] = (rand()&0xFF) | (rand()&0xFF)<<8 |
        (rand()&0xFF)<<16 | (rand()&0xFF)<<24;
    }
}

int cmp(const void* a, const void* b){
	unsigned int *x = (unsigned int*) a;
	unsigned int *y = (unsigned int*) b;
	return *y - *x;
}

int main() {
		int64_t tmp = 0 , duration = 0, max = 0, min = UINT64_MAX;
		int64_t s_dur = 0;
		XTime tstart, tend;
	    int nb_data = 0;

	    unsigned int* data = (unsigned int*)malloc(sizeof(unsigned int)*NB_DATA);

	    xil_printf("\r\nRun at: %s %s\r\n", __DATE__, __TIME__);
	    xil_printf("--- Entering main() --- \r\n");
	    xil_printf("NB_DATA: %d\r\n", NB_DATA);


	    //Multiple runs for a number of data from 4 to DATA_STEP
	    for (int i = 2; i < (MAX_DATA_POWER+1) ; i++)
	    {
	        nb_data = (1<<i);
	        s_dur   = 0;
	        max     = 0;
	        min     = UINT32_MAX;

	        for (int h = 0; h < NB_SETS; h++)
	        {
	            randomize(data, nb_data);
	            // Multiple runs for a given number of data
	            for (int j = 0; j < AVERAGING; j++)
	            {
	            	XTime_GetTime(&tstart);
	            	//trident_sort(data, i);
	            	qsort(data, nb_data, sizeof(unsigned int), cmp);
	                XTime_GetTime(&tend);
	                tmp = (tend-tstart) / (COUNTS_PER_SECOND/1000000);
	                max     = (tmp>max)?tmp:max;
	                min     = (tmp<min)?tmp:min;
	                s_dur   += tmp;

	                for(int a = 0 ; a<(nb_data-1) ; a++){
	                	if(data[a]>data[a+1]){xil_printf("Oh shit\r\n");}

	                }
	            }

	        }

	        duration = s_dur/(AVERAGING*NB_SETS);
	        printf("Run %d data in us =>\r\nAVG : %llu\tMAX : %llu\tMIN: %llu\r\n", nb_data, duration, max, min);
	    }
	        xil_printf("--- Exiting main() --- \r\n");

	return 0;

}


