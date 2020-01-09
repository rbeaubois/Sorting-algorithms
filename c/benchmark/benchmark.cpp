#include "benchmark.h"

// Benchmarking a sort algorithm
void runBenchmark(Comparator *s, unsigned int* data, int n, string sort)
{
	string filename;
	string dir = "../bench_results/";
	filename = dir + sort + "_results.csv"; 

    ofstream outfile;
	outfile.open(filename);
	char sep = ';';

    unsigned int tmp = 0, s_dur = 0, duration = 0, max = 0, min = UINT32_MAX;

	for (int i = 4; i < n; i+= DATA_STEP)
	{
        s_dur   = 0;
        max     = 0;
        min     = UINT32_MAX;
        for (int j = 0; j < AVERAGING; j++)
        {        
            //cout << "Number of elts:" << i << endl;
            tmp     = s->process(data, i);
            max     = (tmp>max)?tmp:max;
            min     = (tmp<min)?tmp:min;
            s_dur   += tmp; 
            //cout << "Duration:" << duration << endl;
        }
        duration = s_dur/AVERAGING;
        outfile << i << sep << duration << sep << max << sep << min << "\n" ;
	}
	outfile.close();
}

// Generate n random datas of type unsigned int
void randomize(unsigned int* data, int n){
    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        data[i] = (rand()&0xFF) | (rand()&0xFF)<<8 |
        (rand()&0xFF)<<16 | (rand()&0xFF)<<24;
    }      
}