#include "tab.h"

void AfficherTab(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%u ", tab[i]);
    }
    printf("\n");
}

void TabFromFile(char *filename, int len, unsigned int tab[])
{
    FILE *fp;

    int j;
    char buffer[16];
    unsigned int var;

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Erreur d'ouverture de fichier \n");
        exit(1);
    }

    while (j < len)
    {
        fgets(buffer, 16, fp);
        sscanf(buffer, "%u\n", &var);
        tab[j] = var;
        j++;
    }
}