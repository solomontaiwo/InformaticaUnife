#include <stdio.h>
#include "funzioneAlQuadrato.h"

int main(int argc, char *argv[]){

    int numero;
    float alQuadrato;

    printf("Inserisci un valore: ");
    scanf("%d", &numero);

    alQuadrato = quadrato(numero);

    printf("Il quadrato di %d e' %.2f.\n", numero, alQuadrato);
    
}