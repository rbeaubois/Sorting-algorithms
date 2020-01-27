#include "benchmark.h"

// Benchmarking a sort algorithm
void runBenchmark(Comparator *s, unsigned int* data, string sort)
{
	string filename;
	string dir = "../benchmarks/";
	filename = dir + sort + "_results.csv"; 

    ofstream outfile;
	outfile.open(filename);
	char sep = ';';

    unsigned int tmp = 0 , duration = 0, max = 0, min = UINT32_MAX;
    unsigned long s_dur = 0;
    unsigned int timer = 0;
    int nb_data = 0;

    cerr << "[Run]" << endl;
    cerr << "\tSize of data sets 2^2 (4) to 2^16 (65536)" << endl;
    cerr << "\tRandom sets benched per step : " << NB_SETS << endl;
    cerr << "\tAveraging per set : " << AVERAGING << endl;

    outfile << '#' << "Data set size: 2^{2} (4) to 2^{16} (65536)" << "\\\\n" <<'#' << "Random sets benched per step:" << NB_SETS << "\\\\n" << '#' << "Averaging per set:" << AVERAGING << endl;

    //Multiple runs for a number of data from 4 to DATA_STEP
    for (int i = 2; i < (MAX_DATA_POWER+1) ; i++)
    {
        nb_data = (1<<i);
        s_dur   = 0;
        max     = 0;
        min     = UINT32_MAX;

        for (int h = 0; h < NB_SETS; h++)
        {
            // Multiple runs for a given number of data
            for (int j = 0; j < AVERAGING; j++)
            {        
                tmp     = s->process(data, i); //nb_data);
                max     = (tmp>max)?tmp:max;
                min     = (tmp<min)?tmp:min;
                s_dur   += tmp; 
                timer++;
            }

            randomize(data, nb_data);
        }      

        duration = s_dur/(AVERAGING*NB_SETS);
        outfile << nb_data << sep << duration << sep << max << sep << min << "\n" ;
        print_progress(timer);
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

// Print time on terminal
void print_progress(unsigned int timer){
    int progress;
    unsigned char barWidth = 40;
    progress = (barWidth*timer)/(AVERAGING*(MAX_DATA_POWER-1)*NB_SETS);

    cerr << "[";
    for (int i = 0; i < barWidth; i++)
    {
        if (progress>i)
            cerr << "=";
        else if(progress == i)
            cerr << ">";
        else
            cerr << " ";      
    }
    cerr << "]";
    cerr << ' ' <<  (100*progress)/barWidth << '%' << '\r';   

    if(progress == barWidth){
        cerr << "100%";
        for (int i = 0; i < barWidth+10; i++)
        {
            cerr << " ";
        }
        cerr << endl;
    } 
}