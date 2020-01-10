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

    unsigned int tmp = 0 , duration = 0, max = 0, min = UINT32_MAX;
    unsigned long s_dur = 0;
    unsigned int timer = 0;

    cerr << "[Run]" << endl;
    cerr << "\tSize of data sets : 4 to " << n << endl;
    cerr << "\tStep : " << DATA_STEP << endl;
    cerr << "\tRandom sets benched per step : " << NB_SETS << endl;
    cerr << "\tAveraging per set : " << AVERAGING << endl;

    outfile << '#' << "Data set size:" << n << endl;
    outfile << '#' << "Step:" << DATA_STEP << endl;
    outfile << '#' << "Random sets benched per step:" << NB_SETS << endl;
    outfile << '#' << "Averaging per set" << AVERAGING << endl;    

    // Multiple runs for a number of data from 4 to DATA_STEP
    // for (int h = 0; h < NB_SETS; h++)
    // {
    //     for (int i = 4; i < n; i+= DATA_STEP)
    //     {
    //         s_dur   = 0;
    //         max     = 0;
    //         min     = UINT32_MAX;
    // 
    //         // Multiple runs for a given number of data
    //         for (int j = 0; j < AVERAGING; j++)
    //         {        
    //             //cout << "Number of elts:" << i << endl;
    //             tmp     = s->process(data, i);
    //             max     = (tmp>max)?tmp:max;
    //             min     = (tmp<min)?tmp:min;
    //             s_dur   += tmp; 
    //             //cout << "Duration:" << duration << endl;
    //             timer++;
    //         }
    // 
    //         duration = s_dur/AVERAGING;
    //         outfile << i << sep << duration << sep << max << sep << min << "\n" ;
    //         print_progress(timer, n);
    //     }        
    //     randomize(data, n);
    // }


    //Multiple runs for a number of data from 4 to DATA_STEP
    for (int i = 4; i < n; i+= DATA_STEP)
    {
        s_dur   = 0;
        max     = 0;
        min     = UINT32_MAX;

        for (int h = 0; h < NB_SETS; h++)
        {
            // Multiple runs for a given number of data
            for (int j = 0; j < AVERAGING; j++)
            {        
                tmp     = s->process(data, i);
                max     = (tmp>max)?tmp:max;
                min     = (tmp<min)?tmp:min;
                s_dur   += tmp; 
                timer++;
            }

            randomize(data, i);
        }      

        duration = s_dur/(AVERAGING*NB_SETS);
        outfile << i << sep << duration << sep << max << sep << min << "\n" ;
        print_progress(timer, n);
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
void print_progress(unsigned int timer, int n){
    int progress;
    unsigned char barWidth = 40;
    progress = (barWidth*timer)/(AVERAGING*(n/DATA_STEP)*NB_SETS);

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