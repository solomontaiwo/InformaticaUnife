void swap(int array[], int primoValore, int secondoValore)
{
    int temp = array[primoValore];
    array[primoValore] = array[secondoValore];
    array[secondoValore] = temp;
}