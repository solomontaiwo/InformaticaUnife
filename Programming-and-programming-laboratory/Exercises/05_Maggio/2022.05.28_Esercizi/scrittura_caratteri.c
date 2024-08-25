#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pfb;
    char messaggio[] = "Ah, l'esame\nsi avvicina!";

    if ((pfb = fopen("testo.txt", "wb")) == NULL)
    {
        printf("Impossibile creare file di testo.\n");
        exit(1);
    }

    fwrite(messaggio, sizeof(messaggio), 1, pfb);

    fclose(pfb);
    return 0;
}