#include <stdio.h>

int main(void)
{
    FILE *ciaoPtr;

    if ((ciaoPtr = fopen("saluti.txt", "w")) == NULL)
    {
        puts("Non ho trovato il file, il programma verra' automaticamente arrestato.");
    }
    else
    {
        puts("Questo programma inserisce in un file di testo i dati da te inseriti relativi a persone casuali da te indicate.");
        puts("Premi la combinazione di EOF del tuo sistema operativo (Windows = ctrl + z, Linux = ctrl + d).");
        printf("%c ", '?');

        unsigned int numeroFrase;
        char frase[50];

        scanf("%d %s", &numeroFrase, frase);

        while (!feof(stdin))
        {
            fprintf(ciaoPtr, "%d %s\n", numeroFrase, frase);
            printf("%c ", '?');
            scanf("%d %s", &numeroFrase, frase);
        }
    }
    fclose(ciaoPtr);
}