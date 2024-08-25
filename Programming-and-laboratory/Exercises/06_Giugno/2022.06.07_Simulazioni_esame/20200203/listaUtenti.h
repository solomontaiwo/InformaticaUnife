typedef struct
{
    char cf[17];
} Iscritto;

typedef struct
{
    char cf[17];
    int attivita;
} Ingresso;

typedef struct
{
    char cf[17];
    int attUno, attDue, attTre;
} Utente;

typedef struct nodo
{
    Utente muscoli;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void creaLista(Lista *pl, Iscritto r);
void aggiornaLista(Lista *pl, Ingresso i);
void stampa(Lista l);