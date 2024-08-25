typedef int Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void creaLista(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
void stampa(Lista l);
void insTesta(Lista *pl, int numero);
Lista *ricerca(Lista *pl, int numero);
Lista *ricercaOrd(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
void elimTesta(Lista *pl);
int elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
void swap(Nodo *a, Nodo *b);
void ordina(Lista *pl);