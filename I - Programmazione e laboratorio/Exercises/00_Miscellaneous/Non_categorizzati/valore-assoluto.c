#include <stdio.h>

int valoreAssoluto(int n)
{
    int va;
    if (n >= 0)
        va = n;
    else
        va = -n;
    return va;
}

int main(void)
{
    int m;
    scanf("%d", &m);
    printf("%d\n", valoreAssoluto(m));
    return 0;
}