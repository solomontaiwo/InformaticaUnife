typedef struct
{
    char Nazione[20];
} Record;

typedef struct
{
    char nomeNazione[20];
    int ori;
    int argenti;
    int bronzi;
} Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, char *r, int numeroCiclo);
void stampa(Lista l);