typedef struct
{
    int matricola, punteggio;
    char prova;
} Risultato;

typedef struct
{
    int matricola, pratica, teorica;
} Candidato;

typedef struct nodo
{
    Candidato cand;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiornaLista(Lista *pl, Risultato ris);
void stampa(Lista l);