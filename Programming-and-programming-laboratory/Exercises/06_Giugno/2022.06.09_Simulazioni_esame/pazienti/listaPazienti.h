#define SIZE 17

typedef struct
{
    char cf[SIZE];
    int ora;
    float temperatura;
    float saturazione;
} Rilevazione;

typedef struct
{
    char cf[SIZE];
    int numeroRilevazioni;
    float temperatura;
    float saturazione;
} Paziente;

typedef struct nodo
{
    Paziente p;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Rilevazione r);
void insTesta(Lista *pl, Paziente p);
void stampa(Lista l);