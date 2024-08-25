#include <stdio.h>
#include <stdlib.h>
#include "svolazziDiClassicismo.h"

int main(int argc, char *argv[])
{
    char nome[20];
    char sesso[10];
    int vite;
    int rispostaDomanda, rispostaCorretta, punteggio = 0;

    system("clear");

    printf("*SVOLAZZI DI CLASSICISMO*\n\n");

    printf("Inserisci il tuo nome:\n\n> ");
    scanf("%s", &nome);

    printf("\nInserisci il tuo sesso (M, F oppure come meglio ti identifichi):\n\n> ");
    scanf("%s", &sesso);

    system("clear");

    benvenuto(sesso, nome);

    puts("*DOMANDA 1*\n");

    printf("Dove si sviluppo', almeno inizialmente, la civilta' ellenica?\n\n1. NELLE ISOLE MINORI OCCIDENTALI DELL'INGHILTERRA E NEI TERRITORI CONTINENTALI DELLE ISOLE SCANDINAVE\n2. IN ARGENTINA, BRASILE ORIENTALE E MESSICO MERIDIONALE\n3. NELLA GRECIA CONTINENTALE\n4. IN AUSTRALIA ORIENTALE E NELLE ISOLE NEOZELANDESI\n\n");

    vite = 3;

    rispostaCorretta = 3;

    while (vite > 0)
    {
        printf("> ");
        scanf("%d", &rispostaDomanda);

        if (rispostaDomanda == rispostaCorretta)
        {
            system("clear");
            printf("Risposta corretta! Successivamente si espanse anche in Albania costiera, nelle isole del Mar Egeo ed in altri territori dell'attuale Europa.\n\n");
            punteggio++;
            break;
        }
        else
        {
            printf("\nSbagliato! ");
            vite--;
            printf("Numero di vite: %d\n", vite);
            puts("");
        }
    }
    if (vite == 0)
        sconfitta(nome, &punteggio, &vite);

    puts("*DOMANDA 2*\n");

    printf("Come venivano chiamati i territori dell'Italia meridionale in cui si insediarono gli antichi greci? (Vite rimanenti: %d)\n\n1. MAGNA GRECIA\n2. TERRANOVA\n3. NOVARTIS\n4. LA SERENISSIMA REPUBBLICA DI PORTIOLO\n\n", vite);

    rispostaCorretta = 1;

    while (vite > 0)
    {
        printf("> ");
        scanf("%d", &rispostaDomanda);

        if (rispostaDomanda == rispostaCorretta)
        {
            system("clear");
            printf("Risposta esatta! Fu uno dei territori piu' prosperoso della civilta' greca.\n\n");
            punteggio++;
            break;
        }
        else
        {
            printf("\nSbagliato! ");
            vite--;
            printf("Numero di vite: %d\n", vite);
            puts("");
        }
    }
    if (vite == 0)
        sconfitta(nome, &punteggio, &vite);

    puts("*DOMANDA 3*\n");

    printf("Che cosa sono le Polis (Poleis)? (Vite rimanenti: %d)\n\n1. DELLE COPPIE DI FENDENTI UTILIZZATE NELLE GUERRE\n2. UN TIPO DI CALZATURA INDOSSATO DALLE DONNE ARISTOCRATICHE DI ATENE\n3. LE FIGLIE ILLEGITTIME DI ZEUS\n4. LA CITTA-STATO DELL'ANTICA GRECIA\n\n", vite);

    rispostaCorretta = 4;

    while (vite > 0)
    {
        printf("> ");
        scanf("%d", &rispostaDomanda);

        if (rispostaDomanda == rispostaCorretta)
        {
            system("clear");
            printf("Giusto. La polis era un modello di struttura tipicamente greca che prevedeva l'attiva partecipazione degli abitanti liberi alla vita politica\n\n");
            punteggio++;
            break;
        }
        else
        {
            printf("\nSbagliato! ");
            vite--;
            printf("Numero di vite: %d\n", vite);
            puts("");
        }
    }
    if (vite == 0)
        sconfitta(nome, &punteggio, &vite);

    puts("*DOMANDA 4*\n");

    printf("Per i greci che cosa significava avvicinarsi alla verità? (Vite rimanenti: %d)\n\n1. AVVICINARSI ALLA SUPREMAZIA SULLE ALTRE POPOLAZIONI\n2. ARRICCHIRSI ECONOMICAMENTE\n3. GODERE DI MAGGIORE PRESTIGIO\n4. AVVICINARSI ALLE DIVINITA'\n\n", vite);

    rispostaCorretta = 4;

    while (vite > 0)
    {
        printf("> ");
        scanf("%d", &rispostaDomanda);

        if (rispostaDomanda == rispostaCorretta)
        {
            system("clear");
            printf("Din din din! I greci attribuivano molta importanza alla conoscenza e alla ricerca della verita': in questo contesto gli antichi greci avevano intuito l'importanza della matematica, della filosofia e delle scienze\n\n");
            punteggio++;
            break;
        }
        else
        {
            printf("\nSbagliato! ");
            vite--;
            printf("Numero di vite: %d\n", vite);
            puts("");
        }
    }
    if (vite == 0)
        sconfitta(nome, &punteggio, &vite);

    puts("*DOMANDA 5*\n");

    printf("Qual e' il nome della citta' in cui gli Achei vennero sconfitti, segnando dunque la fine dell'antica Grecia? (Vite rimanenti: %d)\n\n1. TERMOPILI\n2. CORINTO\n3. SIRACUSA\n4. ROMA\n\n", vite);

    rispostaCorretta = 2;

    while (vite > 0)
    {
        printf("> ");
        scanf("%d", &rispostaDomanda);

        if (rispostaDomanda == rispostaCorretta)
        {
            system("clear");
            printf("Cosi' si fa, %s! Nel 146 a.C. gli Achei furono sconfitti nella Battaglia di Corinto, la città fu rasa al suolo e la Grecia e la Macedonia divennero province della Repubblica romana.\n\n", nome);
            punteggio++;
            break;
        }
        else
        {
            printf("\nSbagliato! ");
            vite--;
            printf("Numero di vite: %d\n", vite);
            puts("");
        }
    }
    if (vite == 0)
        sconfitta(nome, &punteggio, &vite);

    puts("*DOMANDA 6*\n");

    printf("Qual e' il grado di parentela tra Zeus e Poseidone? (Vite rimanenti: %d)\n\n1. CUGINI\n2. PADRE E FIGLIO\n3. FRATELLI\n4. NON HANNO LEGAMI DI SANGUE\n\n", vite);

    rispostaCorretta = 2;

    while (vite > 0)
    {
        printf("> ");
        scanf("%d", &rispostaDomanda);

        if (rispostaDomanda == rispostaCorretta)
        {
            system("clear");
            printf("Corretto! Sono entrambi figli di due titani, Cronos e Rea.\n\n");
            punteggio++;
            break;
        }
        else
        {
            printf("\nSbagliato! ");
            vite--;
            printf("Numero di vite: %d\n", vite);
            puts("");
        }
    }
    if (vite == 0)
        sconfitta(nome, &punteggio, &vite);

    puts("*DOMANDA 7*\n");

    printf("Come venne costretta Persefone a trascorrere sei mesi all'anno nel regno dei morti? (Vite rimanenti: %d)\n\n1. SOTTO MINACCIA DIRETTA DI ADE\n2. NON VENNE COSTRETTA, LO FECE PER AMORE VERSO IL SUO CONSORTE\n3. GLIELO CHIESE SUA MADRE DEMETRA\n4. MANGIANDO I FRUTTI DEGLI INFERI\n\n", vite);

    rispostaCorretta = 4;

    while (vite > 0)
    {
        printf("> ");
        scanf("%d", &rispostaDomanda);

        if (rispostaDomanda == rispostaCorretta)
        {
            system("clear");
            printf("Stai andando alla grande, %s! Una volta negli inferi, A Persefone venne offerta della frutta: ella mangio' senza appetito solo sei semi di melograno, ignorava pero' che chi mangia i frutti degli inferi e' costretto a rimanervi per l'eternita'.\n\n", nome);
            punteggio++;
            break;
        }
        else
        {
            printf("\nSbagliato! ");
            vite--;
            printf("Numero di vite: %d\n", vite);
            puts("");
        }
    }
    if (vite == 0)
        sconfitta(nome, &punteggio, &vite);

    puts("*DOMANDA 8*\n");

    printf("Chi libero' il titano Prometeo, incatenato sulla vetta di un monte da Zeus? (Vite rimanenti: %d)\n\n1. ZEUS\n2. ERCOLE\n3. ERA\n4. PANDORA\n\n", vite);

    rispostaCorretta = 2;

    while (vite > 0)
    {
        printf("> ");
        scanf("%d", &rispostaDomanda);

        if (rispostaDomanda == rispostaCorretta)
        {
            system("clear");
            printf("Certo che sai il fatto tuo, %s! Prometeo era estremamente a favore del benestare degli esseri umani, motivo per cui spesso e volentieri li aiutava a discapito degli dei.\n\n", nome);
            punteggio++;
            break;
        }
        else
        {
            printf("\nSbagliato! ");
            vite--;
            printf("Numero di vite: %d\n", vite);
            puts("");
        }
    }
    if (vite == 0)
        sconfitta(nome, &punteggio, &vite);

    puts("*DOMANDA 9*\n");

    printf("Qual e' il nome della divinita' legata al vento dell'ovest? (Vite rimanenti: %d)\n\n1. ZEPHYR\n2. BOREA\n3. NOTOS\n4. EURO\n\n", vite);

    rispostaCorretta = 1;

    while (vite > 0)
    {
        printf("> ");
        scanf("%d", &rispostaDomanda);

        if (rispostaDomanda == rispostaCorretta)
        {
            system("clear");
            printf("Risposta esatta. Il signore di tutti questi venti è Eolo, che regna su di loro rinchiuso in una grotta nell'isola di Eolia.\n\n");
            punteggio++;
            break;
        }
        else
        {
            printf("\nSbagliato! ");
            vite--;
            printf("Numero di vite: %d\n", vite);
            puts("");
        }
    }
    if (vite == 0)
        sconfitta(nome, &punteggio, &vite);

    puts("*DOMANDA 10*\n");

    printf("Chi e' il padre di Zeus? (Vite rimanenti: %d)\n\n1. CHAOS\n2. URANO\n3. TARTARO\n4. CRONO\n\n", vite);

    rispostaCorretta = 4;

    while (vite > 0)
    {
        printf("> ");
        scanf("%d", &rispostaDomanda);

        if (rispostaDomanda == rispostaCorretta)
        {
            system("clear");
            printf("Congratulazioni, hai risposto correttamente anche a quest'ultima domanda. A Crono si deve il nome della cosiddetta 'sindrome di Crono', la patologia psichica di un padre che desidera, o addirittura esegue, l'omicidio di un proprio figlio.\n\n");
            punteggio++;
            break;
        }
        else
        {
            printf("\nSbagliato! ");
            vite--;
            printf("Numero di vite: %d\n", vite);
            puts("");
        }
    }
    if (vite == 0)
        sconfitta(nome, &punteggio, &vite);
    else if (punteggio == 10)
        vittoria();

    return 0;
}