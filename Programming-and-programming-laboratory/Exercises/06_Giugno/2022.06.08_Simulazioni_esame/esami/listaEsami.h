typedef struct
{
    int matricola;
    int punteggio;
    char prova;
} Studente;

typedef struct
{
    int matricola, pratica, teorica;
} Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Studente s);
void stampa(Lista l);