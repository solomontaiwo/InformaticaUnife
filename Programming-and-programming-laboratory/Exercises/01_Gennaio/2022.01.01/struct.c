// E' una specie di dizionario in C

#include <stdio.h>
#include <stdlib.h>

struct Studente
{
    char *nome;
    int eta;
    int voto;
};

int main()

{
    struct Studente studente1;
    studente1.nome = "Solomon";
    studente1.eta = 25;
    studente1.voto = 80;

    struct Studente studente2;
    studente2.nome = "Pino";
    studente2.eta = 44;
    studente2.voto = 66;

    printf("Lo studente numero uno si chiama %s, ha %d anni ed ha ottenuto il punteggio di %d.\n\n", studente1.nome, studente1.eta, studente1.voto);
    printf("Lo studente numero due si chiama %s, ha %d anni ed ha ottenuto il punteggio di %d.\n", studente2.nome, studente2.eta, studente2.voto);
}