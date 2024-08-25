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
    int giorno, mese, anno;
} Data;

typedef struct
{
    char CF[17];
    int tampone;
    int vaccino;
} Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Record r, Data oggi);
void stampa(Lista l);