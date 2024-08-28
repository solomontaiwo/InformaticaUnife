#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(int argc, char *argv[])
{
    char stringa1[SIZE], stringa2[SIZE];
    int i = 0, l1, l2;

    printf("Inserisci la prima stringa: ");
    fgets(stringa1, sizeof(stringa1), stdin);
    printf("Inserisci la seconda stringa: ");
    fgets(stringa2, sizeof(stringa2), stdin);

    l1 = strlen(stringa1);
    l2 = strlen(stringa2);

    if (l1 == l2)
    {
        while (stringa1[i] == stringa2[i])
        {
            if (stringa1[i] == '\n' && stringa2[i] == '\n')
            {
                printf("Le due stringhe sono uguali.\n");
                break;
            }
            else
            {
                i++;
            }
        }

        if (stringa1[i] != stringa2[i])
            printf("Le stringhe hanno caratteri diversi.\n");
    }
    else
        printf("Le stringhe hanno lunghezza diversa.\n");

    return 0;
}
