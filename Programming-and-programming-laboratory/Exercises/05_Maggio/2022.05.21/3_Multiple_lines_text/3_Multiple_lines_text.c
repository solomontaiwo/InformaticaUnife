/* Write a program in C to write multiple lines in a text file. Go to the editor
Test Data :
Input the number of lines to be written : 4
:: The lines are ::
test line 1
test line 2
test line 3
test line 4
Expected Output :

The content of the file test.txt is  :
test line 1
test line 2
test line 3
test line 4

https://www.w3resource.com/c-programming-exercises/file-handling/ */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *pft;
    int numeroLinee;
    char testo[20] = "linea di test", testoLetto;

    printf("Inserisci il numero di linee da scrivere nel file di testo: ");
    scanf("%d", &numeroLinee);

    if ((pft = fopen("test.txt", "wt")) == NULL)
    {
        printf("Impossibile aprire il file di testo.\n");
        exit(0);
    }

    for (int i = 1; i <= numeroLinee; i++)
    {
        fprintf(pft, "%s %d\n", testo, i);
    }

    puts("");

    fclose(pft);

    if ((pft = fopen("test.txt", "rt")) == NULL)
    {
        printf("Impossibile aprire il file di testo.\n");
        exit(1);
    }

    printf("Il contenuto del file di testo test.txt e': \n");

    while ((testoLetto = fgetc(pft)) != EOF)
    {
        printf("%c", testoLetto);
    }

    fclose(pft);
}