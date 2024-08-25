#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct studente
    {
        char nome[50];
        int anni;
        float voto;
    } Solomon;

    printf("Inserisci le informazioni sullo studente: \n");
    printf("Nome: ");
    scanf("%s", Solomon.nome);
    printf("Anni: ");
    scanf("%d", &Solomon.anni);
    printf("Voto: ");
    scanf("%f", &Solomon.voto);

    printf("\ninformazioni sullo studente:\nNome: %s\nAnni: %d\nVoto: %.1f\n", Solomon.nome, Solomon.anni, Solomon.voto);
}