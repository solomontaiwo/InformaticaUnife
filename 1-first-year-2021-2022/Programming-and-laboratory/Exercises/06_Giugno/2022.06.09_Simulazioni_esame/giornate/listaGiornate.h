typedef struct
{
    int giorno, mese;
    float ore;
    char attivita[30];
} Registrazione;

typedef struct
{
    int giorno, mese;
    float ore;
} Giornata;

typedef struct nodo
{
    Giornata g;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Giornata g);
int giornoUguale(int giorno1, int giorno2, int mese1, int mese2);
void aggiorna(Lista *pl, Registrazione r);
void stampa(Lista l);