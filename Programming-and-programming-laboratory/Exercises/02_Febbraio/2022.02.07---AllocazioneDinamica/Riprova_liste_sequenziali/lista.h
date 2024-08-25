#define DIM 5

typedef struct
{
    int n_elementi;
    int dati[DIM];
} Lista;

void inizializzaLista(Lista *pl);
int listaPiena(Lista l);
int listaVuota(Lista l);
void insOrd(Lista *pl, int numero);
void insTesta(Lista *pl, int numero);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
int lunghezza(Lista l);
void stampa(Lista l);
int ricerca(Lista l, int numero);