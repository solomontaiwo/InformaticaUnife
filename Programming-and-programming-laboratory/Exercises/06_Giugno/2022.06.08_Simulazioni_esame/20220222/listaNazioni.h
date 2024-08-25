#define SIZE 21

typedef char Nazione[SIZE];

typedef struct
{
    char nazione[SIZE];
    int ori;
    int argenti;
    int bronzi;
} Dato;

typedef struct nodo
{
    Dato n;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Nazione n, int posizione);
void stampa(Lista l);