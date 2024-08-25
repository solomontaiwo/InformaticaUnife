typedef struct
{
    char indirizzo[30];
    int vani;
    float distanza;
} Record;

typedef struct
{
    char indirizzo[30];
    int vani;
    float distanza;
} Immobile;

typedef struct nodo
{
    Immobile imm;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Record r);
void stampa(Lista l);