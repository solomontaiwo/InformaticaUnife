#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 25

int main(int argc, char *argv[]){
    
    char parola[SIZE], parolaLetta[SIZE];
    FILE *pft;

    if ((pft = fopen("testoConParolaUtente.txt", "wt")) == NULL)
    {
        printf("Impossibile creare il file richiesto, ri-lancia il programma.\n");
        exit(1);
    }

    printf("Inserisci una parola: ");
    scanf("%[^\n]", parola);

    fprintf(pft, "%s", parola);

    fclose(pft);

    if((pft = fopen("testoConParolaUtente.txt", "rt")) == NULL)
    {
        puts("Impossibile leggere il file richiesto. Il nome e' corretto?");
        exit(2);
    }
    
    fscanf(pft, "%[^\n]", parolaLetta);
    printf("Questa e' la parola letta dal file: %s\n", parolaLetta);

    fclose(pft);
    
}