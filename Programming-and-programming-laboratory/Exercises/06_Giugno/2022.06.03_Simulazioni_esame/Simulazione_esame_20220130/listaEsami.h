typedef struct
{
    int matricola;
    int punteggio;
    char tipoProva;
} Risultato;

typedef struct
{
    int matricola;
    int punteggioPratica;
    int punteggioTeorica;
} Dato;

typedef struct nodo
{
    Dato d;
    struct nodo *next;
} Nodo;

typedef struct
{
    int superato;
    int somma;
} Esito;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void stampa(Lista l);
void aggiorna(Lista *pl, Risultato r);