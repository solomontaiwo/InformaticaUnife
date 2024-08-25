typedef struct
{
    int giorno, mese, anno;
    char cf[17];
    char evento;
} Registrazione;

typedef struct
{
    char cf[17];
    int tampone, vaccino;
} Persona;

typedef struct nodo
{
    Persona per;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Registrazione reg);
void stampa(Lista l);