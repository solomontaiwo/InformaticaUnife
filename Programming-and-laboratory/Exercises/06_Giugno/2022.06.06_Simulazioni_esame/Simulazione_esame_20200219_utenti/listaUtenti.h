typedef struct
{
    char numero[11];
    char piano;
    float credito;
} Record; // per lettura da file .dat

typedef struct
{
    char numero[11];
    int durata;
} Chiamata; // per lettura da file .txt

typedef struct
{
    char numero[11];
    char piano;
    float residuo;
} DatoLista;

typedef struct nodo
{
    DatoLista d;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void aggiornaLista(Lista *pl, Record r);
void stampaLista(Lista l);
