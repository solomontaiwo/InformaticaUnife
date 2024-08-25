#define SIZE 5

typedef struct
{
    int numeroElementi;
    int dati[SIZE];
} Lista;

void inizializzaLista(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
void stampa(Lista l);
int lunghezza(Lista l);
void insOrd(Lista *pl, int numero);
void insTesta(Lista *pl, int numero);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
int ricerca(Lista l, int numero);