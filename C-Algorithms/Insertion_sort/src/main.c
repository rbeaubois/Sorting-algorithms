#include "tab.h"
#include <time.h>

void swap(unsigned int *a, unsigned int *b)
{
    unsigned int tmp = *a;
    *a = *b;
    *b = tmp;
}

void TriSelectif(unsigned int tab[], int n)
{
    int min_index;
    int j;

    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < n; j++)
        {
            if (tab[j] < tab[min_index])
            {
                min_index = j;
            }
        }
        swap(&tab[min_index], &tab[i]);
    }
}
 
 void TriInsertion(unsigned int tab[], int n)
{
    unsigned int pivot;
    int j;

    for (int i = 1; i < n ; i++)
    {
        pivot = tab[i];
        j = i - 1;

        while (j>= 0 && tab[j] > pivot)
        {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j+1] = pivot;
    }
}

int main(int argc, char const *argv[])
{
    int len = atoi(argv[1]);
    unsigned int tab[len];
    char *filename = argv[2];

    TabFromFile(filename, len, tab);

    // AfficherTab(tab,len);
    clock_t begin = clock();
    TriInsertion(tab, len);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // AfficherTab(tab,len);
    printf("Temps: %lf secondes \n", time_spent);
    return 0;
}
