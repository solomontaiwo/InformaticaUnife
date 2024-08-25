#include <stdio.h>
#include <string.h>

int main()
{
    int accesso = 0;
    char password[4];

    printf("Password?\n");
    scanf("%s", password);

    if (strcmp(password, "abc") == 0)
        accesso = 1;
    if (accesso)
        printf("Accesso consentito.\n");
    else
        printf("Accesso negato.\n");
}