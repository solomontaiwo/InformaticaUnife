int grandeArray(int array[])
{
    int grande = 0;
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        if (array[i] > grande)
        {
            grande = array[i];
        }
    }
    return grande;
}