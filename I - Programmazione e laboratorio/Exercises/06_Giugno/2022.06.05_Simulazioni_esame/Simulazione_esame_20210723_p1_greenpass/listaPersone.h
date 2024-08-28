typedef struct
{
    int giorno;
    int mese;
    int anno;
    char cf[17];
    char evento;
} Record;

typedef struct
{
    char cf[17];
    int tampone;
    int vaccino;
} Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Record r);
void stampa(Lista l);