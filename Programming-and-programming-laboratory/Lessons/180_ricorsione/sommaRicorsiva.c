int somma(int N)
{
    if (N == 1)
        return 1;
    else
        somma(N - 1);
}