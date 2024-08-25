typedef int Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void generaLista(Lista *pl);
void reverse(Lista l1, Lista *pl2);
void stampa(Lista l);
void insTesta(Lista *pl, int numero);