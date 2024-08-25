// Crea un file binario dati.dat, inserisci il suo interno un array di numeri e leggi quei numeri dal file, per poi stamparli a video. //
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void insertionSort(int array[], int lunghezza);

int main(void)
{
    FILE *fscritturaLettura;
    int valori[SIZE] = {10, 8, 6, 9, 4, 1, 3, 7, 2, 5};
    int valoriLetti[SIZE];

    if ((fscritturaLettura = fopen("valori.dat", "wb")) == NULL)
    {
        perror("Impossibile aprire il file.\n");
        exit(1);
    }
    else
    {
        printf("Valori prima di inserimento all'interno del file: ");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d ", valori[i]);
        }
        puts("");

        fwrite(valori, sizeof(int), 10, fscritturaLettura);
    }

    fclose(fscritturaLettura);

    printf("Ora leggero' i valori scritti nel file.\n");

    if ((fscritturaLettura = fopen("valori.dat", "rb")) == NULL)
    {
        perror("Impossibile aprire il file.\n");
        exit(2);
    }

    else
    {
        fread(valoriLetti, sizeof(int), 10, fscritturaLettura);

        fclose(fscritturaLettura);

        insertionSort(valoriLetti, SIZE);

        printf("Valori dopo inserimento in ordine all'interno del file: ");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d ", valoriLetti[i]);
        }
        puts("");
    }
}

void insertionSort(int array[], int lunghezza)
{
    for (int i = 1; i < lunghezza; i++)
    {
        int posizioneElemento = i;
        int inserimento = array[i];
        {

            while (posizioneElemento > 0 && array[posizioneElemento - 1] > inserimento)
            {
                array[posizioneElemento] = array[posizioneElemento - 1];
                posizioneElemento--;
            }
        }
        array[posizioneElemento] = inserimento;
    }
}