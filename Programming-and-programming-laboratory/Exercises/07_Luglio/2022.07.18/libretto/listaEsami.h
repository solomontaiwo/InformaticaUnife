typedef struct
{
    int giorno, mese, anno;
    char nomeInsegnamento[50];
    int voto;
} Record;

typedef struct
{
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct nodo
{
    Record r;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiornaLista(Lista *pl, Record r);
void stampaLista(Lista l);
int diffDate(Data d1, Data d2);