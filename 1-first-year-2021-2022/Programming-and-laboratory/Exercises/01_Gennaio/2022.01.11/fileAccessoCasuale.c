#include <stdio.h>

int main(void)
{
    int number;
    FILE *fPtr;
    fwrite(&number, sizeof(int), 1, fPtr);
}