typedef struct
{
    char numero[11];
    char piano;
    float credito;
} Record;

typedef struct
{
    char numero[11];
    float credito;
} Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;

} Nodo;

typedef struct
{
    char numero[11];
    int durata;
} Chiamata;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Record r);
void stampa(Lista l);