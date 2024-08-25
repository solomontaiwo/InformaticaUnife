#include <stdio.h>
#define SIZE 100

int ricercaLineare(int array[], int chiave, int size); // prototipo di funzione

int main(void)
{
    int a[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        a[i] = 2 * i;
    }

    printf("Inserisci il valore da localizzare: ");
    int localizzatore;
    scanf("%d", &localizzatore);

    // tentativo di localizzazione nell'array a

    int indice = ricercaLineare(a, localizzatore, SIZE);

    if (indice != -1)
    {
        printf("Trovato valore nell'elemento %d.\n", indice);
    }
    else
    {
        printf("Valore non trovato.\n");
    }
}
// definizione del prototipo di funzione di ricercaLineare
int ricercaLineare(int array[], int chiave, int size)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] == chiave)
        {
            return i;
        }
    }
    return -1; // chiave non trovata
}
