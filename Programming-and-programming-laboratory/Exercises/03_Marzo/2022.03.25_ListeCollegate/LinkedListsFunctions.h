typedef struct nodo
{
    int dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inizializza(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
void insCoda(Lista *pl, int numero);
void insSort(Lista *pl);
Lista *ricerca(Lista *pl, int numero);
Lista *ricercaPerInsOrd(Lista *pl, int numero);
Lista *ricercaPerInsCoda(Lista *pl, int numero);
Lista *ricercaPerInsTesta(Lista *pl, int numero);
void elim1(Lista *pl, int numero);
void elimTesta(Lista *pl);
void elimCoda(Lista *pl);
void stampa(Lista l);