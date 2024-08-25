typedef struct
{
    int giorno, mese;
    float ore;
    char attivita[30];
} Registrazione;

typedef struct
{
    int giorno, mese;
    float ore;
} Giornata;

typedef struct nodo
{
    Giornata g;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiornaLista(Lista *pl, Registrazione r);
void stampa(Lista l);