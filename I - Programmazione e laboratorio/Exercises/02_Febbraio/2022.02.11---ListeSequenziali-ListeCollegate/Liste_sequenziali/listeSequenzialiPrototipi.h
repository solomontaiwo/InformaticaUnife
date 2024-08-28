#define SIZE 10

typedef struct
{
    int n_elementi;
    int dati[SIZE];
} Lista;

int vuota(Lista l);
int piena(Lista l);
int lunghezza(Lista l);
void inizializza(Lista *pl);
void stampa(Lista l);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
int ricerca(Lista l, int numero);