typedef struct
{
    char codiceFiscale[16];
    int eta;
    char nome[10];
} Persona;

typedef struct nodo
{
    Persona dati;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Persona p);
void stampa(Lista l);
void elimTesta(Lista *pl);
void scriviSuFile(char *nome, int eta, char *codiceFiscale, FILE *f);