typedef struct
{
    char cf[17];
    int oraRilevazione;
    float temperatura, saturazione;
} Rilevazione;

typedef struct
{
    char cf[17];
    float temperatura, saturazione;
    int numeroRilevazioni;
} Paziente;

typedef struct nodo
{
    Paziente p;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Rilevazione r);
void stampa(Lista l);