typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int vuota(Lista l);
int piena(Lista l);
void listaNonOrdinata(Lista *pl, int lunghezza);
void insTesta(Lista *pl, Dato d);
int lunghezza(Lista l);
void stampa(Lista l);

// nuovo, operazioni strutturali derivate

void elimTesta(Lista *pl);
void nuovaLista(Lista *pl);
Lista *ricerca(Lista *pl, int numero);
Lista *ricercaPerInsOrd(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
void insTesta(Lista *pl, int numero);