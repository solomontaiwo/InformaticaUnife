typedef struct
{
    int giorno;
    int mese;
    float oreImpiegate;
    char attivita[30];
} Record;

typedef struct
{
    int giorno;
    int mese;
    float oreTotaliImpiegate;
} Giornata;

typedef struct nodo
{
    Giornata g;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void stampa(Lista l);
void aggiorna(Lista *pl, Record r);