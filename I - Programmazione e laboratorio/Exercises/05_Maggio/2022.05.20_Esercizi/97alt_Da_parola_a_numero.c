#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char parola[10];

    printf("Scrivi un numero da uno a dieci: ");
    scanf("%s", parola);

    if ((strcmp(parola, "uno")) == 0)
        printf("Uno\n");
    else if ((strcmp(parola, "due")) == 0)
        printf("Due\n");
    else if ((strcmp(parola, "tre")) == 0)
        printf("Tre\n");
    else if ((strcmp(parola, "quattro")) == 0)
        printf("Quattro\n");
    else if ((strcmp(parola, "cinque")) == 0)
        printf("Cinque\n");
    else if ((strcmp(parola, "sei")) == 0)
        printf("Sei\n");
    else if ((strcmp(parola, "sette")) == 0)
        printf("Sette\n");
    else if ((strcmp(parola, "otto")) == 0)
        printf("Otto\n");
    else if ((strcmp(parola, "nove")) == 0)
        printf("Nove\n");
    else if ((strcmp(parola, "dieci")) == 0)
        printf("Dieci\n");
}
