#include <stdio.h>

int main(int argc, char *argv[])
{
    float inch, cm;

    printf("Inserisci un valore in pollici: ");
    scanf("%f", &inch);
    printf("Valore in cm: %.2f\n", 2.54 * inch);
}