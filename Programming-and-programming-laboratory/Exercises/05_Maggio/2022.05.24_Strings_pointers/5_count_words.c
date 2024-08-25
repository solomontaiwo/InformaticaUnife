#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char stringa[100], l;
    int contaParole = 0, i = 0;

    printf("Inserisci una stringa: ");
    fgets(stringa, sizeof(stringa), stdin);

    l = strlen(stringa);

    for (i = 0; i <= l; i++)
    {
        if (stringa[i] == ' ')
        {
            contaParole++;
        }
    }

    printf("Numero totale di parole: %d\n", contaParole+1);

    return 0;
}