// client dell'ADT Frazione

#include "frazione.h"

int main() {
  Frazione fr, fr2;
  Frazione arrayFrazioni[100];
  // creo variabile di tipo Frazione che rappresenta il numero razionale 2/3
  // fr = frazione(2,3);
  fr = sottrazione(frazione(5, 6), frazione(3, 4));
  stampaFrazione(fr);
  return 0;
}