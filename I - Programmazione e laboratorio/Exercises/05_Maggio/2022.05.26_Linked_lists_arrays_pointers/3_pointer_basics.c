#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 7;
    int *ptr = &a;

    printf("L'indirizzo di a e' %p\n", &a);
    printf("Il valore di ptr e' %p\n", ptr);
    printf("Il valore di a e' %d\n", a);
    printf("Il valore di *ptr e' %d\n", *ptr);

    printf("* e & sono complementari:\n&*ptr = %p\n*&ptr = %p\n", &*ptr, *&ptr);

    return 0;
}