#include <stdio.h>

int main(int argc, char *argv[])
{
    float metri, piedi;

    printf("Inserisci un valore in metri: ");
    scanf("%f", &metri);

    piedi = metri * 3.26;

    printf("Valore in piedi: %.2f\n", piedi);
}