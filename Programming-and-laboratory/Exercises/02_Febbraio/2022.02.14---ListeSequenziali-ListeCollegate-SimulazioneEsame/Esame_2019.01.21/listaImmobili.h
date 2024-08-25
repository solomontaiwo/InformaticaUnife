typedef struct
{
    char indirizzo[30];
    int nVani;
    float distanzaDalCentro;
} Immobile;

typedef struct nodo
{
    Immobile dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void insOrd(Lista *pl, Immobile imm);
Lista filtra(Lista l, int nVaniMin);
void stampa(Lista l, FILE *f);