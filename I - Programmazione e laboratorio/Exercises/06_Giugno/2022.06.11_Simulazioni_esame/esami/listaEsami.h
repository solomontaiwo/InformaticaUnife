typedef struct
{
    int matricola;
    int punteggio;
    char tipoProva;
} Risultato;

typedef struct
{
    int matricola, punteggioPratica, punteggioTeorica;
} Studente;

typedef struct nodo
{
    Studente s;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Studente s);
void aggiorna(Lista *pl, Risultato r);
void voto(int teorica, int pratica);
void riordino(Lista *pl);
void stampa(Lista l);