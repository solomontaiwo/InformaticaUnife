#include <stdio.h>
#include <stdlib.h>

struct persona
{
    char cognome[31], nome[31], sesso[2];
    int anno;
};

struct persona leggi();

int main(int argc, char *argv[])
{
    FILE *pfb;
    struct persona e;
    int fine = 0;
    pfb = fopen("people.dat", "wb");
    while (!fine)
    {
        e = leggi();
        fwrite(&e, sizeof(struct persona), 1, pfb);
        printf("\nFine (SI = 1, NO = 0) ? ");
        scanf("%d", &fine);
    }
    fclose(pfb);
}

struct persona leggi()
{

    struct persona e;

    printf("Cognome ? ");
    scanf("%s", e.cognome);
    printf("Nome ? ");
    scanf("%s", e.nome);
    printf("Sesso ? ");
    scanf("%s", e.sesso);
    printf("Anno nascita ? ");
    scanf("%d", &e.anno);

    return e;
}