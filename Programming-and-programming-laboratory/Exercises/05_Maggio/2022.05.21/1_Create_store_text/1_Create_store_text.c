/* Write a program in C to create and store information in a text file.
Test Data :
Input a sentence for the file : This is the content of the file test.txt.
Expected Output :

The file test.txt was successfully created! 
https://www.w3resource.com/c-programming-exercises/file-handling/ */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pft;
    if ((pft = fopen("test.txt", "wr")) == NULL)
    {
        printf("Can't create file.\n");
        exit(1);
    }
    else
    {
        fprintf(pft, "This is the content of the file test.txt.");
        printf("The file \"test.txt\" was successfully created!\n");
    }

    fclose(pft);
}