#define SIZE 5

typedef struct
{
    int numeroElementi;
    int dati[SIZE];
} Lista;

void nuovaLista(Lista *pl);
int piena(Lista l);
int vuota(Lista l);
int ricerca(Lista l, int numero);
void insOrd(Lista *pl, int numero);
void insTesta(Lista *pl, int numero);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
void stampa(Lista l);