#define SIZE 5

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

typedef struct
{
    int n_elementi;
    int dato[SIZE];
} Lista;