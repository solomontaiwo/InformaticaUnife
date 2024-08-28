typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int vuota(Lista l);
int piena(Lista l);
void azzera(Lista l);
void listaNonOrdinata(Lista *pl, int n);
void stampa(Lista l);