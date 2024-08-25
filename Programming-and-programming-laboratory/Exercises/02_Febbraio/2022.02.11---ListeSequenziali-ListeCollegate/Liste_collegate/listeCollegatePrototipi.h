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