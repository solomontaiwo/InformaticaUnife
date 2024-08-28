typedef struct
{
    char cf[17];
    int ora;
    float temperatura;
    float saturazione;
} Record;

typedef struct
{
    char cf[17];
    int numeroRilevazioni;
    float temperatura;
    float saturazione;
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