// il tag nodo è necessario per permettere la compilazione (altrimenti il compilatore non saprebbe che cos'è il campo next)

typedef struct nodo
{
    int dato;
    struct nodo *next; // puntatore al nodo successivo
} Nodo;