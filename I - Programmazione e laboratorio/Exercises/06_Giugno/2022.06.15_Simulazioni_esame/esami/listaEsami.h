typedef struct
{
    int matricola, punteggio;
    char prova;
} Risultato;

typedef struct
{
    int matricola, punteggioPratica, punteggioTeorica;
} Candidato;

typedef struct nodo
{
    Candidato can;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiorna(Lista *pl, Risultato ris);
void stampa(Lista l);