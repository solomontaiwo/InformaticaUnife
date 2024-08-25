/* Write a program in C to merge two files and write it in a new file.

Assume that the content of the file test.txt and test1.txr is :
The content of the file test.txt is  :
This is the file test.txt.

The content of the file test1.txt is  :
This is the file test1.txt.
Test Data :
Input the 1st file name : test.txt
Input the 2nd file name : test1.txt
Input the new file name where to merge the above two files : mergefiles.txt
Expected Output :

The two files merged into mergefiles.txt file successfully..!!
Here is the content of the merge file mergefiles.txt :

The content of the file mergefiles.txt is  :
This is the file test.txt.
This is the file test1.txt.

https://www.w3resource.com/c-programming-exercises/file-handling/ */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *pft1, *pft2, *pft3;
    char nomeFileUnito[30], nomePrimoFile[30], nomeSecondoFile[30];
    char testo1[50], testo2[50], testoFinale[50];
    int i = 0, k = 0, j = 0;

    printf("Inserisci il nome del primo file: ");
    scanf("%s", nomePrimoFile);
    printf("Inserisci il nome del secondo file: ");
    scanf("%s", nomeSecondoFile);
    printf("Inserisci il nome del terzo file: ");
    scanf("%s", nomeFileUnito);

    if ((pft1 = fopen(nomePrimoFile, "rt")) == NULL)
    {
        printf("Impossibile aprire il primo file di testo %s\n", nomePrimoFile);
        exit(0);
    }

    if ((pft3 = fopen(nomeFileUnito, "wt")) == NULL)
    {
        printf("Impossibile creare il nuovo file unito %s\n", nomeFileUnito);
        exit(1);
    }

    while ((testo1[i] = fgetc(pft1)) != EOF)
    {
        fprintf(pft3, "%c", testo1[i]);
        i++;
    }

    fclose(pft1);
    fclose(pft3);

    if ((pft2 = fopen(nomeSecondoFile, "rt")) == NULL)
    {
        printf("Impossibile aprire il secondo file di testo %s\n", nomeSecondoFile);
        exit(2);
    }

    if ((pft3 = fopen(nomeFileUnito, "at")) == NULL)
    {
        printf("Impossibile aggiungere al nuovo file unito %s\n", nomeFileUnito);
        exit(3);
    }

    while ((testo2[k] = fgetc(pft2)) != EOF)
    {
        fprintf(pft3, "%c", testo2[k]);
        k++;
    }

    puts("");

    fclose(pft2);
    fclose(pft3);

    if ((pft3 = fopen(nomeFileUnito, "rt")) == NULL)
    {
        printf("Impossibile aprire il file di testo %s\n", nomeFileUnito);
        exit(4);
    }

    printf("Questo e' il contenuto del file unito chiamato %s:\n", nomeFileUnito);

    while ((testoFinale[j] = fgetc(pft3)) != EOF)
    {
        printf("%c", testoFinale[j]);
        j++;
    }

    puts("");

    fclose(pft3);
}
