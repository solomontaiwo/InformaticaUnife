#include <stdio.h>

int main(int argc, char *argv[])
{

    int n1, n2, n3, grande;

    printf("Inserisci tre valori: ");

    scanf("%d %d %d", &n1, &n2, &n3);

    /*  if (n1 > n2 && n1 > n3)
      {
          grande = n1;
      }
      else if (n2 > n1 && n2 > n3)
      {
          grande = n2;
      }
      else
          grande = n3; */

    grande = n1;

    if (grande < n2)
        grande = n2;
    if (grande < n3)
        grande = n3;

    printf("Il valore piu' grande e' %d.\n", grande);
}