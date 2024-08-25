#define SIZE 10

typedef struct
{
    int n_elementi;
    int dato[SIZE];
} Lista;

void inizializza(Lista *pl);
int piena(Lista l);
int vuota(Lista l);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
int ricerca(Lista l, int numero);
void stampa(Lista l);