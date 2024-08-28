typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void listaNuova(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
void elimTesta(Lista *pl);
Lista *ricerca(Lista *pl, Dato d);
Lista *ricercaOrd(Lista *pl, Dato d);
void elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);
int lunghezza(Lista l);
void stampa(Lista l);