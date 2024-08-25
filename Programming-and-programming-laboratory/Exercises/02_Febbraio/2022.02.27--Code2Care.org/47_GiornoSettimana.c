#include <stdio.h>

int main(int argc, char *argv[])
{

    int giorno;

    printf("Inserisci un numero da 1 a 7: ");
    scanf("%d", &giorno);

    switch (giorno)
    {
    case 1:
        printf("Lunedi'\n");
        break;
    case 2:
        printf("martedi'\n");
        break;
    case 3:
        printf("Mercoledi'\n");
        break;
    case 4:
        printf("Giovedi'\n");
        break;
    case 5:
        printf("Venerdi'\n");
        break;
    case 6:
        printf("Sabato\n");
        break;
    case 7:
        printf("Domenica\n");
        break;
    default:
        printf("Hai inserito un numero non valido.\n");
    }
}