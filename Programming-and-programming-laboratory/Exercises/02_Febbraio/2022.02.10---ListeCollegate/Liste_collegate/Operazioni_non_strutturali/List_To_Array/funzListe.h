typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int vuota(Lista l);
int piena(Lista l);
void generaListaNonOrdinata(Lista *pl, int numero);
void stampa(Lista l);
int* listToArray(Lista l);
int lunghezza(Lista l);
