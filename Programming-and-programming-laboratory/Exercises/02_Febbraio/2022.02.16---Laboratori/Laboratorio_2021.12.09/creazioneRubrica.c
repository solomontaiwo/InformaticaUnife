#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[20];
    char indirizzo[30];
    char telefono[15];
} Persona;

int main(int argc, char *argv[])
{
    FILE *pft;
    FILE *pfb;
    Persona persone[5] = {{"Mario_Rossi", "Via_Roma_15", "333_1234567"}, {"Giulia_Bianchi", "Piazza_Milano_23", "347_7654321"}, {"Elisa_Verdi", "Via_Italia_44", "348_11122233"}, {"Maria_Russo", "VIale_Cavour_18", "320_3849234"}, {"Carlo_Esposito", "Via_Mazzini_25", "380_98765432"}};

    pft = fopen("rubrica.txt", "wt");

    pfb = fopen("rubrica.dat", "wb");

    if (pft == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        exit(1);
    }
    else

    {
        for (int i = 0; i < 5; i++)
            fprintf(pft, "%s %s %s\n", persone[i].nome, persone[i].indirizzo, persone[i].telefono);
    }

    if (pfb == NULL)
    {
        printf("Errore nell'apertura rubrica.dat.\n");
        exit(2);
    }
    else

    {
        for (int i = 0; i < 5; i++)
            fwrite(&persone[i], sizeof(Persona), 1, pfb);
    }

    if (fclose(pft) != 0)
    {
        printf("Errore chiusura file.\n");
        exit(3);
    }

    if (fclose(pfb) != 0)
    {
        printf("Errore chiusura file binario.\n");
        exit(4);
    }
    return 0;
}