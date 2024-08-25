// Interfaccia ADT lista

#define DIM 100

typedef struct
{
    int n_elementi;
    int dati[DIM];
} Lista;

void nuovaLista(Lista *pl);
int piena(Lista l);
int lunghezza(Lista l);
void insOrd(Lista *pl, int numero);
void stampa(Lista l);