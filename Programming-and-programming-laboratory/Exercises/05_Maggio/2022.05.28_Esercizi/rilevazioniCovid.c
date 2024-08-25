#include <stdio.h>
#include <stdlib.h>

struct pazienti
{
    char cf[17];
    int oraRilevazione;
    float temperatura;
    float saturazione;
};

int main(int argc, char *argv[])
{
    FILE *pfb;
    if (argc != 2)
    {
        printf("Errore argomento.\n");
        exit(1);
    }

    if ((pfb = fopen(argv[1], "rb")) == NULL)
    {
        printf("Impossibile leggere il file in argomento.\n");
        exit(2);
    }

    struct pazienti e[5];

    while (!feof(pfb))
    {
        fread(e, sizeof(struct pazienti), 1, pfb);
        printf("%s %d %f %f\n", e->cf, e->oraRilevazione, e->saturazione, e->temperatura);
    }

    fclose(pfb);
    return 0;
}