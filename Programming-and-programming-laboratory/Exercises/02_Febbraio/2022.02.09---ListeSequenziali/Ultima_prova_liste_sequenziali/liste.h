#define SIZE 10

typedef struct
{
    int n_elementi;
    int dati[SIZE];
} Lista;

void inizializza(Lista *pl);

int piena(Lista l);

int vuota(Lista l);

void insTesta(Lista *pl, int numero);

void insOrd(Lista *pl, int numero);

void elimina1(Lista *pl, int numero);

void eliminaTutti(Lista *pl, int numero);

int stampa(Lista l);

int ricerca(Lista l, int numero);

int lunghezza(Lista l);