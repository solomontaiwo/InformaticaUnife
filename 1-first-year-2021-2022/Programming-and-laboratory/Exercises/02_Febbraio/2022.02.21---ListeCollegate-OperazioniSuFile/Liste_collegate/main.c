#include "funzioniListeCollegateEsame.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    Lista l;

    inizializza(&l);

    insTesta(&l, 7);

    insTesta(&l, 9);

    printf("Prima stampa: ");
    stampa(l);

    insCoda(&l, 1);

    printf("Seconda stampa, dopo inserimento in coda: ");
    stampa(l);

    insertionSort(&l);

    printf("Terza stampa, dopo insertion sort: ");
    stampa(l);

    elim1(&l, 1);

    printf("Quarta stampa, dopo eliminazione 1: ");
    stampa(l);

    insTesta(&l, 7);

    printf("Quinta stampa, dopo inserimento in testa: ");
    stampa(l);

    elimTutti(&l, 7);

    printf("Sesta stampa, dopo eliminazione di tutti i 7: ");
    stampa(l);
}