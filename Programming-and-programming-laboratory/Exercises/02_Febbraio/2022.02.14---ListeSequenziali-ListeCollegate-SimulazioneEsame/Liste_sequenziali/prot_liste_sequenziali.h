#define SIZE 5

typedef struct
{
    int n_elementi;
    int dato[SIZE];
} Lista;

void inizializza(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
int lunghezza(Lista l);
void listaNonOrdinata(Lista *pl, int numeroElementi);
void stampa(Lista l);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);