#define SIZE 17

typedef struct
{
    char cf[SIZE];
} Iscritto;

typedef struct
{
    char cf[SIZE];
    int attivita;
} Ingresso;

typedef struct
{
    char cf[SIZE];
    int primaAttivita, secondaAttivita, terzaAttivita;
} Utente;

typedef struct nodo
{
    Utente u;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Utente u);
void creaLista(Lista *pl, Iscritto i);
void aggiornaLista(Lista *pl, Ingresso i);
void stampa(Lista l);
