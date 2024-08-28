typedef struct
{
    char targa[8];
    float oreSosta;
} Accesso;

typedef struct
{
    char targa[8];
    int contatore;
} Veicolo;

typedef struct nodo
{
    Veicolo v;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void creaLista(Lista *pl, Accesso a);
void stampa(Lista l);
void fattura(float numeroAccessi);