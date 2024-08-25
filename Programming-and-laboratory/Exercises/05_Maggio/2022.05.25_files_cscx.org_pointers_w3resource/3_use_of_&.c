#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Pointer : Demostrate the use of & and * operator : \n");
    printf("- - - - - - - - - - - - - - - - -\n");

    int m = 300;
    float fx = 300.600006;
    char cht = 'z';

    printf("m = %d\n", m);
    printf("fx = %f\n", fx);
    printf("cht = %c\n", cht);

    printf("\nUsing & operator :\n");
    printf("- - - - - - - - - - - - - - - - -\n");
    printf("Address of m = %p\n", &m);
    printf("Address of fx = %p\n", &fx);
    printf("Address of cht = %p\n", &cht);

    printf("\nUsing & and * operator :\n");
    printf("- - - - - - - - - - - - - - - - -\n");
    int *pt1 = &m;
    printf("Value at address of m = %d\n", *pt1);
    float *pt2 = &fx;
    printf("Value at address of fx = %f\n", *pt2);
    char *pt3 = &cht;
    printf("Value at address of cht = %c\n", *pt3);

    printf("\nUsing only pointer variable :\n");
    printf("- - - - - - - - - - - - - - - - -\n");
    printf("Address of m = %p\n", pt1);
    printf("Address of fx = %p\n", pt2);
    printf("Address of cht = %p\n", pt3);

    printf("\nUsing only pointer operator :\n");
    printf("- - - - - - - - - - - - - - - - -\n");
    printf("Value at address of m = %d\n", *pt1);
    printf("Value at address of fx = %f\n", *pt2);
    printf("Value at address of cht = %c\n", *pt3);

    return 0;
}