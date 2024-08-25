#include <stdio.h>
#include <stdlib.h>
#include "frazioni.h"

int MCD(int a, int b) {
  while (a != b)
    if (a > b)
      a = a - b;
    else
      b = b - a;
  return a;
}

int valAssoluto(int d) {
  return d >= 0 ? d : -d;
}

Frazione frazione(int n, int d) {
  Frazione f;
  int m = MCD(valAssoluto(n), valAssoluto(d));
  f.num = n / m;
  f.den = d / m;
  return f;
}

Frazione leggiFrazione(void) {
  // richiede all'utente num e den e restituisce la corrispondente frazione
  int n, d;
  printf("Digita numeratore e denominatore\n");
  scanf("%d%d", &n, &d);
  return frazione(n, d);
  ;
}

Frazione somma(Frazione f1, Frazione f2) {
  return frazione(f1.num * f2.den + f1.den * f2.num, f1.den * f2.den);
}

void stampaFrazionaria(Frazione f) {
  printf("%d/%d", f.num, f.den);
}

void stampaDecimale(Frazione f) {
  printf("%f", (float)f.num / f.den);
}