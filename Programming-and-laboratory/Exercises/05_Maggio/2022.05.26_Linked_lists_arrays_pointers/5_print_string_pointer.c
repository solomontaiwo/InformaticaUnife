#include <stdio.h>
void printCharbyChar(char *ptr);

int main(int argc, char *argv[])
{
    char stringa[20];
    printf("Inserisci una stringa: ");
    scanf("%s", stringa);

    printCharbyChar(stringa);

    return 0;
}

void printCharbyChar(char *ptr)
{
    for (; *ptr != '\0'; ptr++)
        printf("%c ", *ptr);
    puts("");
}
