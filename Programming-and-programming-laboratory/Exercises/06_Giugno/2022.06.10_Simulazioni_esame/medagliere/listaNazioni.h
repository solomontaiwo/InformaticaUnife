#define SIZE 20
typedef char Posizioni[SIZE];

typedef struct
{
    char nomeNazione[SIZE];
    int ori, argenti, bronzi;
} Nazione;

typedef struct nodo
{
    Nazione n;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Posizioni p, int medaglia);
void insTesta(Lista *pl, Nazione n);
void stampa(Lista l);