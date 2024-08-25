#include <stdio.h>

int max(int num1, int num2, int num3)
{
    int result;

    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}
int main()
{

    printf("%d\n", max(3, 10));
    return 0;
}