#include <stdio.h>
main()
{
    int n;
    printf("Dammi un numero, ti dirò se è pari o dispari.\n");
    scanf("%d", &n);
    if (n % 2 == 0)
        printf("%d è pari.\n", n);
    else
        printf("%d è dispari.\n", n);
}