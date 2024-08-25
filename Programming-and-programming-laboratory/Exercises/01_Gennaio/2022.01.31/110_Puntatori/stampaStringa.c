#include <stdio.h>

void f(char *s)
{
    while (*s)
        printf("%c", *s++);
}

int main()
{
    f("Hello\n");
    return 0;
}