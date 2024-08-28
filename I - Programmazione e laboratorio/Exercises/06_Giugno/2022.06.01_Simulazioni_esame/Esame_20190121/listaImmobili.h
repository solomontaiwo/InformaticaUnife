typedef struct
{
    char indirizzo[30];
    int vani;
    float distanzaCentro;
} Immobile;

typedef struct nodo
{
    Immobile dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inizializzaLista(Lista *pl);
void insTesta(Lista *pl, Immobile d);
void insOrd(Lista *pl, Immobile imm);
void stampa(Lista l);