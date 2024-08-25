#include <stdio.h>

int main(int argc, char *argv[])
{

    int numero;

    printf("Inserisci un numero da uno a dieci: ");
    scanf("%d", &numero);

    switch (numero)
    {
    case 1:
        printf("Uno\n");
        break;
    case 2:
        printf("Due\n");
        break;
    case 3:
        printf("Tre\n");
        break;
    case 4:
        printf("Quattro\n");
        break;
    case 5:
        printf("Cinque\n");
        break;
    case 6:
        printf("Sei\n");
        break;
    case 7:
        printf("Sette\n");
        break;
    case 8:
        printf("Otto\n");
        break;
    case 9:
        printf("Nove\n");
        break;
    case 10:
        printf("Dieci\n");
        break;
    }
}
