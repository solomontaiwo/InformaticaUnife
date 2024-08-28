typedef struct
{
    int numeroChip;
    char tipoVaccino;
} Record;

typedef struct
{
    int numeroCane;
    int cimurro;
    int epatite;
    int parvovirosi;
} Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Record r);
void stampa(Lista l);