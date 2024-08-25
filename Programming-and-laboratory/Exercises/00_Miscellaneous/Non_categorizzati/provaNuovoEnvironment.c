#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    printf("Di seguito un numero generato casualmente tra 1 e 31: ");

    srand(time(NULL));

    printf("%d\n", 1 + rand() % (31 - 1 + 1));
}