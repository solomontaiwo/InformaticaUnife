#include <stdio.h>

int main(void)
{

    FILE *ciaoPtr;

    if ((ciaoPtr = fopen("ciao.txt", "w")) == NULL)
    {
        puts("Non sono riuscito ad aprire il file");
    }
}