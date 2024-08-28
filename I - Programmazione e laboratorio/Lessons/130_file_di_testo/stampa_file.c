// Si mostri a video il contentuto di un file di testo il cui nome viene inserito da tastiera

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char nomefile[50];
    char c;

    printf("Quale file apro?\n");
    scanf("%s", nomefile);

    if ((fp = fopen(nomefile, "rt")) == NULL)
    {
        printf("Errore nell'apertura di %s\n", nomefile);
        exit(1);
    }
    while (fscanf(fp, "%c", &c) == 1)
    {
        printf("%c", c);
    }
    if (fclose(fp) != 0)
    {
        printf("Errore nella chiusura del file\n");
        exit(2);
    }
    printf("\n");
}