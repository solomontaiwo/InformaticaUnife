typedef int Dato;
typedef struct nodo {
    Dato d;
    struct nodo *next;
} Nodo;
typedef Nodo *Lista;

int vuota(Lista l);
int piena(Lista l);
void creaLista(Lista *pl);
void stampa(Lista l);
Lista *ricerca(Lista *pl, int numero);
Lista *ricercaOrd(Lista *pl, int numero);
void insTesta(Lista *pl, int numero);
void insOrd(Lista *pl, int numero);
void elimTesta(Lista *pl);
int elim1(Lista *pl, int numero);
void elimTutti(Lista *pl, int numero);