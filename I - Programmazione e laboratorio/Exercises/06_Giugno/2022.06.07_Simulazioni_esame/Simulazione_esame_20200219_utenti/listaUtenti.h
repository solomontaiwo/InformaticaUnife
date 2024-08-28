typedef struct
{
    char numero[11];
    char piano;
    float credito;
} Record; // file binario

typedef struct
{
    char numero[11];
    int durata;
} Chiamata; // file di testo

typedef struct nodo
{
    Record r;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void creaLista(Lista *pl, Record r);
void aggiornaLista(Lista *pl, Chiamata c);
void stampa(Lista l);