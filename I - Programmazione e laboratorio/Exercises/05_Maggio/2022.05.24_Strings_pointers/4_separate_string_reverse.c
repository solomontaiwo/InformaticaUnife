#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char stringa[100];
    int i, l;
    printf("Inserisci una stringa: ");
    fgets(stringa, sizeof(stringa), stdin);

    l = strlen(stringa);

    printf("Caratteri della stringa al contrario:\n");
    for (i = l; l >= 0; l--)
        printf("%c ", stringa[l]);

    puts("");

    return 0;
}