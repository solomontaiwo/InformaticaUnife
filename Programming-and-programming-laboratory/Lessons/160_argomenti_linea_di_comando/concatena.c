#include <stdio.h>
#include <stdlib.h>

void ricopia(FILE *f_out, char nome_in[]);

int main(int argc, char *argv[])
{
    FILE *f_out;
    int i;
    if (argc < 2)
    {
        printf("Uso: %s file_out.txt file1.txt ... fileN.txt\n", argv[0]);
        exit(3);
    }

    if ((f_out = fopen(argv[1], "wt")) == NULL)
    {
        printf("Errore apertura %s in scrittura.\n", argv[1]);
        exit(4);
    }
    for (i = 2; i <= argc - 1; i++)
        ricopia(f_out, argv[i]);

    if (fclose(f_out) != 0)
    {
        printf("Errore chiusura file %s\n", argv[1]);
        exit(5);
    }
    return 0;
}

void ricopia(FILE *f_out, char nome_in[])
{
    FILE *f_in;
    char c;
    if ((f_in = fopen(nome_in, "rt")) == NULL)
    {
        printf("Errore apertura %s\n", nome_in);
        exit(1);
    }

    while (fscanf(f_in, "%c", &c) == 1)
        fprintf(f_out, "%c", c);

    if (fclose(f_in) != 0)
    {
        printf("Errore chiusura file %s\n", nome_in);
        exit(2);
    }
}