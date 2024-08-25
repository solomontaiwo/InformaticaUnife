typedef struct nodo
{
    int dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int vuota(Lista l);
int piena(Lista l);
void inizializza(Lista *pl);
void listaNonOrdinata(Lista *pl, int numero);
void stampa(Lista l);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
void elimTesta(Lista *pl);
void elim1(Lista *pl, int numero);
Lista *ricercaElim1(Lista *pl, int numero);
Lista *ricercaPerOrdinato(Lista *pl, int numero);
Lista *ricercaPerCoda(Lista *pl);
void insertionSort(Lista *pl);