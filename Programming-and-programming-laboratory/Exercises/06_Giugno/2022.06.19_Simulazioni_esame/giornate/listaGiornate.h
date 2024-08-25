typedef struct
{
    int giorno, mese;
    float ore;
    char attivita[30];
} Record;

typedef struct
{
    int giorno, mese;
    float oreLavorate;
} Giornata;

typedef struct nodo
{
    Giornata g;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Record r);
void stampa(Lista l);