#include <stdio.h>
#include <stdlib.h>

void printLista(struct node *p);

struct node
{
    int data;
    struct node *next;
};

int main()
{
    // inizializzo dei nodi
    struct node *testa;
    struct node *nodo1 = NULL;
    struct node *nodo2 = NULL;
    struct node *nodo3 = NULL;

    // alloco la memoria
    nodo1 = malloc(sizeof(struct node));
    nodo2 = malloc(sizeof(struct node));
    nodo3 = malloc(sizeof(struct node));

    // assegno i valori con l'operatore freccia
    nodo1->data = 17;
    nodo2->data = 86;
    nodo3->data = 53;

    // collego i nodi tra di loro
    nodo1->next = nodo2;
    nodo2->next = nodo3;
    nodo3->next = NULL;

    // salvo indirizzo del primo nodo come inizio della lista
    testa = nodo1;

    // stampo lista
    printLista(testa);
}

// funzione per stampare la lista

void printLista(struct node *p)
{
    while (p != NULL)
    {

        if (p->next != NULL)
            printf("|%d| -> ", p->data);
        else
            printf("|%d|", p->data);

        p = p->next;
    }
}