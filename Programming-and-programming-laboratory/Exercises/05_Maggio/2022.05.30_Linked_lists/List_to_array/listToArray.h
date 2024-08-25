typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void generaLista(Lista *pl);
void stampa(Lista l);
int lunghezza(Lista l);
int *listToArray(Lista l);