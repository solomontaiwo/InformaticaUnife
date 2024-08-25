#define SIZE 5

typedef struct
{
    int numeroElementi;
    int dati[SIZE];
} Lista;

void inizializza(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
int ricerca(Lista l, int numero);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
void elimElemento1(Lista *pl, int numero);
void stampa(Lista l);