#include <stdio.h>
#include <stdlib.h>

int newData;

struct node
{
    int data;
    struct node *next;
};

void listInsert(struct node **head, int new_data);
void listDisplay(struct node *p);
int listSearch(struct node **, int);
void listDelete(struct node **, int);

int main()
{
    struct node *head = NULL;
    int nodocercato, nodoCancellato;

        listInsert(&head, newData = 53);
    listInsert(&head, newData = 86);
    listInsert(&head, newData = 17);

    listDisplay(head);
    listInsert(&head, newData = 12);
}

void listInsert(struct node **head, int new_data)
{
    struct node *nuovo = (struct node *)malloc(sizeof(struct node));
    if (nuovo == NULL)
    {
        printf("Errore nell'allocazione della memoria.");
        exit(0);
    }

    nuovo->data = newData;
    nuovo->next = (*head);

    // cambio testa della lista
    (*head) = nuovo;
}

void listDisplay(struct node *p)
{
    printf("\n");

    while (p != NULL)
    {
        printf("|%d| -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}