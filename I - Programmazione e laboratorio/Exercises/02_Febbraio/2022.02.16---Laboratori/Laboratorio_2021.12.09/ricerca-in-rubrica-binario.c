#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char indirizzo[30];
    char numero[15];
} Persona;

int main(int argc, char *argv[])
{
    FILE *pf;
    char nome[20];
    Persona p;

    printf("Digira il nome da ricercare\n");
    scanf("%s", nome);

    if ((pf = fopen("rubrica.dat", "rb")) == NULL)
    {
        printf("Impossibile aprire il file di dati.\n");
        exit(1);
    }

    while (fread(&p, sizeof(Persona), 1, pf) == 1)
    {
        if (strcmp(p.nome, nome) == 0)
            printf("%s %s %s\n", p.nome, p.indirizzo, p.numero);
    }

    fclose(pf);

    return 0;
}