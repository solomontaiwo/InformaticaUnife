typedef char Nome;

typedef struct nodo
{
    int n;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inizializzaLista(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
void insTesta(Lista *pl, int p);
void insCoda(Lista *pl, int p);
void elimTesta(Lista *pl);
void stampa(Lista l);