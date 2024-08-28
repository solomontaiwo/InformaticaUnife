#include <stdio.h>

int numeroDipendenti(int vecchi, int nuovi)
{
    return vecchi + nuovi;
}

int main()
{

    printf("Benvenuto nel programma di conteggio dipendenti della Solomon SPA. Ti diro' da quante persone e' costituita la squadra di questa grande azienda.\n\n");

    int vecchi = 20;
    int nuovi = 15;

    printf("I dipendenti senior all'interno dell'azienda sono %d.\n", vecchi);
    printf("I neo-assunti sono %d.\n", nuovi);

    int (*numeroDipendentiPtr)(int, int);
    numeroDipendentiPtr = &numeroDipendenti;

    int dipendentiTotali = numeroDipendentiPtr(vecchi, nuovi);

    printf("\nI dipendenti totali della multinazionale al 31/12/2021, come riportato dall'HR, sono %d.\n\n", dipendentiTotali);
}