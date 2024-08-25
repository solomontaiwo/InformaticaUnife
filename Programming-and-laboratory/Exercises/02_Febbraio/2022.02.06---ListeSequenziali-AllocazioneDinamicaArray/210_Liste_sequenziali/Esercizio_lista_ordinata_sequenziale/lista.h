#define DIMENSIONI 50

typedef struct
{
    int n_elementi;
    int dati[DIMENSIONI];
} Lista;

void inizializzaLista(Lista *pl);
int lunghezza(Lista l);
int listaPiena(Lista l);
void insOrd(Lista *pl, int numero);
void stampa(Lista l);