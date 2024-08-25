#include <stdio.h>

int main(void)
{
    int giorno, mese, anno;
    puts("Inserisci giorno, mese ed anno: ");
    scanf("%d%*c%d%*c%d", &giorno, &mese, &anno);

    printf("\nLa data che hai inserito e' %d/%d/%d.\n", giorno, mese, anno);
    printf("La data che hai inserito e' %d-%d-%d.\n\n", giorno, mese, anno);

    puts("Prova di allineamento data inserita precedentemente:");
    printf("%-9s%-6s%6s\n", "Giorno", "Mese", "Anno");
    printf("%-9d%-8d%d\n\n", giorno, mese, anno);
}