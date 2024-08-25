#include <stdio.h>
int main(void)
{
    struct nodo
    {
        int numero;
        char caratteri;
        float valorePercentuale;
    };

    int nuovoPtr = malloc(sizeof(struct nodo));

    free(nuovoPtr);
    
    nuovoPtr = NULL;
}