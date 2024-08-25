typedef struct
{
    int matricola;
    int punteggio;
    char prova;
} Record;

typedef struct
{
    int pratica;
    int teorica;
} Punteggio;

typedef struct
{
    int matricola;
    Punteggio pun;
} Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Record r);
void stampa(Lista l);