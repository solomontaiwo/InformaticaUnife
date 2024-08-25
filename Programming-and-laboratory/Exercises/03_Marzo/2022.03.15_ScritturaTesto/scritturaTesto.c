#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *parola = malloc(sizeof(char) + 256);
    FILE *testo;

    if ((testo = fopen("scritturaTesto.txt", "wt")) == NULL)
    {
        printf("Impossibile aprire file di testo.\n");
        exit(1);
    } 

    fgets(parola, 256, stdin);
    fprintf(testo, "%s", parola);

    fclose(testo);
    return 0;
}