#include <stdio.h>
int main(void)
{
    int i;
    int numeri[5];
    
    for (i = 0; i < 5; i++)
        scanf("%d", &numeri[i]);
    for (i = 4; i >= 0; i--)
        printf("%d ", numeri[i]);
    return 0;
}
