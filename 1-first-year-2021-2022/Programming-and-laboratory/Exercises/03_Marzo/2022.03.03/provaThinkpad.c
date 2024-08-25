#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%d\n", 50 + rand() % (60 - 50 + 1));
}