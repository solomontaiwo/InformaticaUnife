typedef int Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inizializzaLista(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
void stampa(Lista l);
void insTesta(Lista *pl, int numero);
void elimTesta(Lista *pl);
void insOrd(Lista *pl, int numero);
Lista *ricerca(Lista *pl, int numero);
Lista *ricercaOrd(Lista *pl, int numero);
int elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
void ordinaLista(Lista *pl);
void swap(Nodo *a, Nodo *b);