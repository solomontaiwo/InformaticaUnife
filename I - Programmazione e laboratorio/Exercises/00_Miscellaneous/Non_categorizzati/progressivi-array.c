#include <stdio.h>

int main(void)
{

    int num;
    int a[9];
    int i;

    printf("Inserisci un numero:\n");
    scanf("%d", &num);
    for (i = 0; i < 10; i++)
        printf("%d\n", a[i] = num + 1 + i);

    return 0;
}