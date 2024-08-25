typedef struct
{
    char targa[8];
    float durata;
} Accesso;

typedef struct
{
    char targa[8];
    int accessi;
} Veicolo;

typedef struct nodo
{
    Veicolo dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inizializzaLista(Lista *pl);
void aggiorna(Lista *pl, char targa[]);
float importo(int accessi);
void stampaImporti(Lista l);