// Scrivere una funzione che, dato un intero, allochi e restituisca una stringa di caratteri della dimensione specificata //
#include <stdlib.h>

void allocazioneStringa(int dimensione)
{
    return (char *)malloc(dimensione * sizeof(char));
}