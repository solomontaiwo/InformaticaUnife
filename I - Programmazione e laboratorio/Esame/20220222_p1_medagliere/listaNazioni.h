#define SIZE 20

typedef char nomeNazione[SIZE];

typedef struct
{
    nomeNazione nm;
    int ori, argenti, bronzi;
} Nazione;

typedef struct nodo
{
    Nazione n;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiornaLista(Lista *pl, nomeNazione nm, int posizione);
void stampaLista(Lista l);