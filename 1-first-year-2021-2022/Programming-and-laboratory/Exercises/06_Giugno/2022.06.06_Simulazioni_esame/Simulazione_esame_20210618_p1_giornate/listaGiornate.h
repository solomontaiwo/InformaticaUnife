typedef struct
{
    int giorno;
    int mese;
    float ore;
    char attivita[30];
} Record;

typedef struct
{
    int giorno;
    int mese;
    float ore;
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