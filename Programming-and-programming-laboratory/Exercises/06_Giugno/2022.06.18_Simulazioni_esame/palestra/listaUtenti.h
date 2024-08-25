typedef char cf[17];

typedef struct
{
    char cf[17];
    int attivita;
} Ingresso;

typedef struct
{
    char cf[17];
    int primaAttivita, secondaAttivita, terzaAttivita;
} Utente;

typedef struct nodo
{
    Utente ut;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void creaLista(Lista *pl, cf codiceFiscale);
void aggiornaLista(Lista *pl, Ingresso in);
void stampa(Lista l);