// Leggere da tastiera un numero e, se è compreso fra 1 e 7, visualizzare il giorno della settimana corrispondente (ad esempio se l’utente digita 2 bisogna scrivere “martedì”) //

#include <stdio.h>

int main()
{
    printf("Inserisci un numero, riportero' il giorno della settimana corrispondente: ");

    int giorno;

    scanf("%d", &giorno);

    if (giorno == 1)
    {
        printf("Lunedi'\n");
    }
    else
    {
        if (giorno == 2)
        {
            printf("Martedi'.\n");
        }
        else
        {
            if (giorno == 3)
            {
                printf("Mercoledi'.\n");
            }
            else
            {
                if (giorno == 4)
                {
                    printf("Gioveei'.\n");
                }
                else
                {
                    if (giorno == 5)
                    {
                        printf("Venerdi'.\n");
                    }
                    else
                    {
                        if (giorno == 6)
                        {
                            printf("Sabato'.\n");
                        }
                        else
                        {
                            if (giorno == 7)
                            {
                                printf("Domenica'.\n");
                            }
                            else
                            {
                                printf("Spiacente, hai inserito un valore non compreso tra 1 e 7.\n");
                            }
                        }
                    }
                }
            }
        }
    }
}