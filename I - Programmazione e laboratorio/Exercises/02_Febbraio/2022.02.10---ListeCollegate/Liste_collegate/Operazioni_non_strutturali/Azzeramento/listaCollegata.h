typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inizializza(Lista *pl);
int piena(Lista l);
int vuota(Lista l);
void stampa(Lista l);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
int ricerca(Lista l, int numero);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
int lunghezza(Lista l);
void azzera(Lista l);
void listaNonOrdinata(Lista *pl, int n);