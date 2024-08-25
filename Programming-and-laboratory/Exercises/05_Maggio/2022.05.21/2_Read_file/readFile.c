/* Write a program in C to read an existing file.
Test Data :
Input the file name to be opened : test.txt
Expected Output :

The content of the file test.txt is  :
This is the content of the file test.txt. 
https://www.w3resource.com/c-programming-exercises/file-handling/ */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    char lettera;

    if ((pft = fopen("test.txt", "rt")) == NULL)
    {
        printf("Impossibile leggere il file.\n");
        exit(1);
    }

    printf("Contenuto del file test.txt: \n");
    while ((fscanf(pft, "%c", &lettera)) != EOF)
    {
        printf("%c", lettera);
    }
    puts("");

    fclose(pft);
}