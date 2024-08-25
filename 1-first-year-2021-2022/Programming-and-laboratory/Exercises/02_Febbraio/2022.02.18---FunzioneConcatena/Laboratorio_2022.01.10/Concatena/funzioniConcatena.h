typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

int vuota(Lista l);
int piena(Lista l);
void inizializza(Lista *pl);
void insTesta(Lista *pl, Dato d);
void insCoda(Lista *pl, Dato d);
void concatena(Lista *pl1, Lista pl2);
void stampa(Lista l);
void insOrd(Lista *pl, Dato d);
int ricerca(Lista l, Dato d);