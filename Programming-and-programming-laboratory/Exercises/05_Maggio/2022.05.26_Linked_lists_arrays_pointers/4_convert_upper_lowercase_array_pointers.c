#include <stdio.h>
#include <ctype.h>

void uppercase(char *ptr);
void lowercase(char *ptr);

int main(int argc, char *argv[])
{
    char stringa[20];
    printf("Inserisci una stringa: ");
    scanf("%s", stringa);
    uppercase(stringa);
    printf("Stringa in minuscolo: %s\n", stringa);
    lowercase(stringa);
    printf("Stringa in maiuscolo: %s\n", stringa);

    return 0;
}

void uppercase(char *ptr)
{
    while (*ptr != '\0')
    {
        *ptr = toupper(*ptr);
        ptr++;
    }
}

void lowercase(char *ptr)
{
    while (*ptr != '\0')
    {
        *ptr = tolower(*ptr);
        ptr++;
    }
}