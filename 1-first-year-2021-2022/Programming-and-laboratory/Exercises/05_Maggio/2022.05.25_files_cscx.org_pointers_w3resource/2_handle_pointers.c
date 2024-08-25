#include <stdio.h>

int main(int argc, char *argv[]){
    int m = 29;

    printf("Address of m : %p\n", &m);
    printf("value of m : %d\n\n", m);

    printf("Now ab is assigned with the address of m.\n");

    int *ab = &m;

    printf("Address of pointer ab : %p\n", ab);
    printf("Content of pointer ab : %d\n\n", *ab);

    printf("The value of m assigned to 34 now.\n");

    m = 34;

    printf("Address of pointer ab : %p\n", ab);
    printf("Content of pointer ab : %d\n\n", *ab);

    printf("The pointer variable ab is assigned with the value 7 now.\n");

    *ab = 7;

    printf("Address of m: %p\n", &m);
    printf("Value of m : %d\n", m);

    return 0;


}