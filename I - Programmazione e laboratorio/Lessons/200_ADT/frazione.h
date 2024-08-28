// interfaccia dell'ADT Frazione

typedef struct {
  int num;
  int den;
} Frazione;

// costruttore
Frazione frazione(int n, int d);

// selettori
int numeratore(Frazione f);
int denominatore(Frazione f);

// input-output
Frazione leggiFrazione();
void stampaFrazione(Frazione f);
void stampaDecimale(Frazione f);


// funzioni
Frazione somma(Frazione f1, Frazione f2);
Frazione opposto(Frazione f);
Frazione sottrazione(Frazione f1, Frazione f2);
float aFloat(Frazione f);

// trasformatore
Frazione semplifica(Frazione f);
// void semplifica(Frazione *pf);