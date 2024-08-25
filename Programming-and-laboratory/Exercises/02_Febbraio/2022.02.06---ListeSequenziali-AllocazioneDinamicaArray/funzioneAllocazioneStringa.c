#include <stdlib.h>

char *alloca(int n)
{
    return (char *)malloc(n * sizeof(char));
}
}