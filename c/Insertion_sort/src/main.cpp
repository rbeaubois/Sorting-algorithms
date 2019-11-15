#include "file2tab.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    unsigned int tabb[6];

    file2tab *rnd_tab = new file2tab("../../data/random.txt", atoi(argv[1]), tabb);
    
    rnd_tab->setLen(atoi(argv[1]));
    rnd_tab->printTab();

    for (int i = 0; i < rnd_tab->getLen(); i++)
    {
        cout<<tabb[i]<<' ';
    }
    cout<<endl;
    
    return 0;
}
