#define DIM 10

typedef struct
{
    int n_elementi;
    int dati[DIM];
} Lista;

int piena(Lista l);
void inizializza(Lista *pl);
void insOrd(Lista *pl, int numero);
void stampa(Lista l);
int lunghezza(Lista l);