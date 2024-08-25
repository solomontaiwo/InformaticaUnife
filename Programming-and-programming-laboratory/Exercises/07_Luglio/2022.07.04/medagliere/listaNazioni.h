typedef char Nazione[20];

typedef struct
{
    Nazione n;
    int ori, argenti, bronzi;
} Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiornaLista(Lista *pl, Nazione n, int posizione);
void stampa(Lista l);