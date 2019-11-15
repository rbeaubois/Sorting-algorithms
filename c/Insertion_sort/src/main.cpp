#include "file2tab.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    file2tab *rnd_tab = new file2tab("random.txt", atoi(argv[1]));
    rnd_tab->setLen(atoi(argv[1]));
    rnd_tab->printTab();
    return 0;
}
