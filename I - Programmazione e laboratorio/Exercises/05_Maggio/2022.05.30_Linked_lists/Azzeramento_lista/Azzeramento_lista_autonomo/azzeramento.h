typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void generaLista(Lista *pl, int lunghezza);
void azzera(Lista l);
void stampa(Lista l);