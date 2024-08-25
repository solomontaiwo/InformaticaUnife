typedef struct
{
    char cf[17];
    int ora;
    float temperatura, saturazione;
} Rilevazione;

typedef struct
{
    char cf[17];
    int numeroRilevazioni;
    float temperatura, saturazione;
} Paziente;

typedef struct nodo
{
    Paziente paz;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Rilevazione ril);
void stampa(Lista l);