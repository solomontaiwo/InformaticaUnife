#include <stdio.h>
#include <stdlib.h>

char lettera = 'A';

int main()
{
    switch (lettera)
    {
    case 'A':
        printf("Sei un primate, l'indivduo alpha.\n");
        break;
    case 'B':
        printf("Non hai manie di protagonismo, pero' sei molto competitivo!\n");
        break;
    case 'C':
        printf("Ne' caldo ne' freddo, non ho molto da dire su di te.\n");
        break;
    case 'D':
        printf("Non ti interessa molto la mia opinione, vero?\n");
    default:
        printf("Non riesco (ancora) a definire che tipo di persona sei in base al carattere che hai immesso, ma ci sto lavorando!\n");
    }
    return 0;
}