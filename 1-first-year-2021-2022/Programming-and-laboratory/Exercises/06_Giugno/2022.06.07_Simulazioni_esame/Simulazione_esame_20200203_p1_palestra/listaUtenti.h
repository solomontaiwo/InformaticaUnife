typedef struct
{
    char codiceFiscale[17];
} Utente;

typedef struct nodo
{
    char codiceFiscale[17];
    int primaAttivita;
    int secondaAttivita;
    int terzaAttivita;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

typedef struct
{
    char codiceFiscale[17];
    int attivita;
} Entrata;

void nuovaLista(Lista *pl);
void creaLista(Lista *pl, Utente e);
void aggiorna(Lista *pl, Entrata e);
void aggiorna2(Lista *pl, Entrata e);
void stampa(Lista l);