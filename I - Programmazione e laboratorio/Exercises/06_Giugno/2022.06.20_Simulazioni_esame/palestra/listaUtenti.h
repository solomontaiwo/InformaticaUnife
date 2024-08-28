#define SIZE 17

typedef char CodiceFiscale[SIZE];

typedef struct
{
    CodiceFiscale cf;
    int attivita;
} Ingresso;

typedef struct
{
    CodiceFiscale cf;
    int primaAttivita, secondaAttivita, terzaAttivita, blocco;
} Utente;

typedef struct nodo
{
    Utente ut;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void creaLista(Lista *pl, CodiceFiscale cf);
void aggiornaLista(Lista *pl, Ingresso in);
void stampa(Lista l);