#include <stdio.h>
#include <stdlib.h>
#include "listaEsami.h"

int main(int argc, char *argv[])
{
    FILE *fp;

    if ((fp = fopen("prove.dat", "rb")) == NULL)
    {
        printf("Impossibile aprire il file.\n");
        exit(-1);
    }

    else 
    {
        
    }
}