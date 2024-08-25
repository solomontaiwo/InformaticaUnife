typedef char nomeNazione[20];

typedef struct
{
    char nazione[20];
    int ori, argenti, bronzi;
} Nazione;

typedef struct nodo
{
    Nazione n;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiornaLista(Lista *pl, nomeNazione naz, int posizione);
void stampaLista(Lista l);