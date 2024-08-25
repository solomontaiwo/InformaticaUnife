#include <stdlib.h>
#include <stdio.h>

void benvenuto(char *identificazione, char *nomeProprio)
{
    switch (*identificazione)
    {
    case 'M':
        printf("Ciao %s, benvenuto nel quiz 'Svolazzi di Classicismo'.\nTi aspettano cinque domande di difficolta' gradualmente maggiore che ti separano da una piacevolissima sorpresa. Per ottenerla devi rispondere in modo corretto, ovviamente!\n\n", nomeProprio);
        break;
    case 'F':
        printf("Ciao %s, benvenuta nel quiz 'Svolazzi di Classicismo'.\nTi aspettano cinque domande di difficolta' gradualmente maggiore che ti separano da una piacevolissima sorpresa. Per ottenerla devi rispondere in modo corretto, ovviamente!\n\n", nomeProprio);
        break;
    default:
        printf("Ciao %s, benvenut* nel quiz 'Svolazzi di Classicismo'.\nTi aspettano cinque domande di difficolta' gradualmente maggiore che ti separano da una piacevolissima sorpresa. Per ottenerla devi rispondere in modo corretto, ovviamente!\n\n", nomeProprio);
        break;
    }
}

void vittoria()
{
    int scelta;

    printf("Complimenti, hai vinto! Hai diritto ad una ricompensa, sceglie attentamente un numero da 1 a 3:\n\n> ");

    scanf("%d", &scelta);

    switch (scelta)
    {
    case 1:
        printf("\nAvvicinati al programmatore...\n\n");
        break;
    case 2:
        printf("\nEhm, il mio budget e' molto limitato. Che dire... grazie per aver giocato!\n\n");
        break;
    case 3:
        printf("\nChiedi qualsiasi cosa al programmatore, ti rispondera' con onesta.\n\n");
        break;
    default:
        printf("\nHai inserito un valore non valido, quindi non posso mostrarti le ricompense, pero' congratulazioni per aver giocato ed aver vinto!\n\n");
        break;
    }
}

void sconfitta(char *nominativo, int *punti, int *lives)
{
    if (*lives == 0)
    {
        printf("Mi dispiace %s, ma hai perso. Cerca di approfondire i tuoi studi sulla Grecia Antica, poi riprova a fare questo quiz! Grazie per aver giocato.\n\nPunteggio: %d\n\n", nominativo, *punti);
        exit(1);
    }
}