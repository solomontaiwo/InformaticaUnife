typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int vuota(Lista l);
void stampa(Lista l);
void insTesta(Lista *pl, int numero);
void listaNonOrdinata(Lista *pl, int numeroElementi);
