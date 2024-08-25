typedef int Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
int listaVuota(Lista l);
int listaPiena(Lista l);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
Lista *ricercaOrd(Lista *pl, int numero);
void stampa(Lista l);
void elimTesta(Lista *pl);
int elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);