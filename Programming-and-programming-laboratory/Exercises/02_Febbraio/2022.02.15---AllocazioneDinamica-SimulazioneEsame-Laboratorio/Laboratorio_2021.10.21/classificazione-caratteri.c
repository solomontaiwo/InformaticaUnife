#include <stdio.h>

int main(int argc, char *argv[])
{
    char c;
    scanf("%c", &c);

    if (c >= 97 && c <= 122)
        printf("Minuscola\n");
    else if (c > 64 && c <= 90)
        printf("Maiuscola\n");
    else if (c > 48 && c <= 57)
        printf("Numero\n");
    else
        printf("Altro\n");
}