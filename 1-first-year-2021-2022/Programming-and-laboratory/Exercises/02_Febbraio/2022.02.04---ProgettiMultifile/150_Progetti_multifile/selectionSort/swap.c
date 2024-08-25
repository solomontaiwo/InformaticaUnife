void swap(int array[], int primoValore, int secondovalore)
{
    int temp = array[primoValore];
    array[primoValore] = array[secondovalore];
    array[secondovalore] = temp;
}