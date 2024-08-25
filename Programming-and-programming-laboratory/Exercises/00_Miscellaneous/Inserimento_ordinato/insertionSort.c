void insertionSort(int array[], int lunghezza)
{
    for (int i = 1; i < lunghezza; i++)
    {
        int posizioneElemento = i;
        int elemento = array[i];
        {
            while (posizioneElemento > 0 && array[posizioneElemento - 1] > elemento)
            {
                array[posizioneElemento] = array[posizioneElemento - 1];
                posizioneElemento--;
            }
        }
        array[posizioneElemento] = elemento;
    }
}