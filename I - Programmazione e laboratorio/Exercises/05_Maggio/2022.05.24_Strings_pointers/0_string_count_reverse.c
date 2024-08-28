#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(int argc, char *argv[])
{
    char stringa[SIZE];
    int i, l;

    printf("Inserisci una stringa: ");
    fgets(stringa, sizeof(stringa), stdin);

    l = strlen(stringa);

    printf("Lunghezza stringa: %d\n", l-1);

    printf("Stringa inserita: \n");

    for (i = 0; i <= l; i++)
        printf("%c ", stringa[i]);

    puts("");

    printf("Stringa invertita: \n");
    for (i = l; i >= 0; i--)
        printf("%c ", stringa[i]);

    puts("");

    return 0;
}