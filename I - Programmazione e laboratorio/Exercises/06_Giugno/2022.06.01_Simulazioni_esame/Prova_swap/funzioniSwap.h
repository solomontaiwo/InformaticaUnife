typedef int Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
int vuota(Lista l);
int piena(Lista l);
void insTesta(Lista *pl, Dato d);
void stampa(Lista l);

int contaLista(Lista l);
void ordinaLista(Lista *pl, int numeroElementi);

void swap(int *a, int *b);