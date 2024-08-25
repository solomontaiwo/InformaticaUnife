typedef struct
{
    char url[100];
    int ora, minuti;
} Visita;

typedef struct
{
    char url[100];
    int numeroVisite;
} Sito;

typedef struct nodo
{
    Sito s;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Visita v);
void aggiornaOrario(Lista *pl, Visita v);
void stampa(Lista l);