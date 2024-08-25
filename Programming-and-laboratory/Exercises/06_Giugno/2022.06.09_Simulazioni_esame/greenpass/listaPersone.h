#define SIZE 17

typedef struct
{
    int giorno, mese, anno;
    char cf[SIZE];
    char evento;
} Record;

typedef struct
{
    char cf[SIZE];
    int vaccino, tampone;
} Paziente;

typedef struct nodo
{
    Paziente p;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Record r);
void stampa(Lista l);