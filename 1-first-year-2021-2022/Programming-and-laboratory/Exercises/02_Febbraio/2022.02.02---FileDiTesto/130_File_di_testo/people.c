/* Si vuole scrivere un programma che
1. legga riga per riga i dati dal file people.txt
2. e ponga i dati in un array di persone
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    typedef struct
    {
        char cognome[30], nome[30], sesso[1];
        int annoNascita;
    } persona;

    persona p1;

    FILE *fpeople;

    if ((fpeople = fopen("people.txt", "rt")) == NULL)
        printf("Il file non è stato trovato.\n");
    else
        fscanf(fpeople, "%s %s %s %d", p1.cognome, p1.nome, p1.sesso, &p1.annoNascita);

    fclose(fpeople);

    printf("Ecco i valori ricavati dal file people.txt:\n%s %s %s %d\n", p1.cognome, p1.nome, p1.sesso, p1.annoNascita);
}