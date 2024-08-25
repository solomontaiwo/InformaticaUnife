#include <stdio.h>

int main(int argc, char *argv[])
{
    char stringa[50], carattere, i = 0;
    printf("Inserisci una stringa: ");
    fgets(stringa, sizeof(stringa), stdin);

    printf("I caratteri della stringa sono:\n");

    while (stringa[i] != '\n')
    {
        printf("%c ", stringa[i]);
        i++;
    }

    puts("");

    return 0;
}