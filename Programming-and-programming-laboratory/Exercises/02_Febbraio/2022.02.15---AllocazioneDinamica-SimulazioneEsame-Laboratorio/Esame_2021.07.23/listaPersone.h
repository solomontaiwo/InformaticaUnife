typedef struct
{
    int giorno;
    int mese;
    int anno;
    char CF[17];
    char evento;
} Record;

typedef struct
{
    char CF[17];
    int vaccino;
    int tampone;
} Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);

void aggiorna(Lista *pl, Record r);

void stampa(Lista l);