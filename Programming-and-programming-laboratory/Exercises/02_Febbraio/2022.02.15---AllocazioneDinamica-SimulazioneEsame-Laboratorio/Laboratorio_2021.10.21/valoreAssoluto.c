#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;

    scanf("%d", &n);

    printf("%d\n", n >= 0 ? n : -n);
}