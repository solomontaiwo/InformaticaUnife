#include <stdio.h>

typedef struct
{
    char nome[10];
    int stipendio;
} persona;

int main()
{
    persona P;
    FILE *f;
    f = fopen("stipendi.dat", "r+b");
    while (fread(&P, sizeof(persona), 1, f) == 1)
    {
        if (P.stipendio < 1000)
        {
            P.stipendio = P.stipendio + (P.stipendio / 10);
            fseek(f, -(long)sizeof(persona), SEEK_CUR);
            fwrite(&P, sizeof(persona), 1, f);
        }
    }
    fclose(f);
}
