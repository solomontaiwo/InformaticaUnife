typedef struct
{
    int chipCane;
    char vaccino;
} Record;

typedef struct
{
    int chipCane;
    int cimurro, epatite, parvovirosi;
} Cane;

typedef struct nodo
{
    Cane c;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Record r);
void stampa(Lista l);