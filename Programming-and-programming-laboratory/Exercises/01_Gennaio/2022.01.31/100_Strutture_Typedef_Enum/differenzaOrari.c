/* Si leggano da tastiera due orari, ciascuno costituito da un numero intero di ore e di minuti, e li si inseriscano in opportune strutture.
Si calcoli il tempo trascorso tra il primo e il secondo orario (supponendo che il secondo sia successivo nel tempo) 
*/
#include <stdio.h>

int main()
{
    struct orari
    {
        int ore, minuti;
    } primoOrario, secondoOrario, differenza;

    printf("Inserisci due orari:\n");

    scanf("%d %d", &primoOrario.ore, &primoOrario.minuti);

    scanf("%d %d", &secondoOrario.ore, &secondoOrario.minuti);

    differenza.minuti = secondoOrario.minuti - primoOrario.minuti;
    if (differenza.minuti < 0)
    {
        differenza.minuti = differenza.minuti + 60;
        secondoOrario.ore--;
    }

    differenza.ore = secondoOrario.ore - primoOrario.ore;

    printf("Differenza fra orari: %d:%d\n", differenza.ore, differenza.minuti);
}