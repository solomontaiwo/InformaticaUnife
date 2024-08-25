typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int lunghezza(Lista l);

void stampa(Lista l);

void listaNonOrdinata(Lista *pl, int n);