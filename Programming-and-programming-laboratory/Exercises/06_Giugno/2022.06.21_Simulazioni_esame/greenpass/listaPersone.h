typedef struct {
    int giorno, mese, anno;
    char cf[17];
    char evento;
} Record;

typedef struct {
    char cf[17];
    int tampone, vaccino;
} Persona;

typedef struct nodo {
    Persona p;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void aggiornaLista(Lista *pl, Record r);
void stampaLista(Lista l);