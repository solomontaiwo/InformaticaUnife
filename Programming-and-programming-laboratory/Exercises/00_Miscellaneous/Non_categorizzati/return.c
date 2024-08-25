#include <stdio.h>

double cube(double num)
{
    double result = num * num * num;
    return result;
}

int main()
{
    printf("Answer: %f\n", cube(2.0));

    return 0;
}