#include <stdio.h>

union uTemp
{
    double a;
    int b[20];
    char c;
} u;

int main(int argc, char *argv[])
{
    printf("%d\n", sizeof(u));
}