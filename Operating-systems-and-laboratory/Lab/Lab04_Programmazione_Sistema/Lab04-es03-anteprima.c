#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

/* dimensione massima del nome del file */
#define DIM 50

int main(int argc, char** argv) {
	
	int pid, status, fd, num;
	char nome[DIM];
	
	/* Controllo il numero degli argomenti */
	if (argc != 2) {
		printf("Uso: ./anteprima <num>\n");
		exit(1);
	}
	
	/* atoi non rileva errori di conversione, 
		meglio usare strtol() / strtoul() */
	if ((num = atoi(argv[1])) <= 0) {
		printf("Errore: %s deve essere un intero positivo maggiore di zero\n", argv[1]);
		exit(2);
	}
	
	printf("Inserisci il nome del file di cui visualizzare "
					"l'anteprima (\"fine\" per uscire): ");
	scanf("%s", nome);
	
	while ( strcmp(nome, "fine") != 0 ) {
		/* per controllare se il file esiste, provo ad aprirlo */
		if ((fd = open(nome, O_RDONLY)) < 0) {
			/* la open potrebbe fallire anche se il file esiste,
		   	 * ad esempio nel caso manchino i permessi di lettura.
			 * Per gestire la differenza, possiamo guardare il
			 * valore di errno.
			 */
			 if (errno == ENOENT) {
				 printf("Il file %s non esiste\n", nome);
			 } 
			 else {
				 /* Errore generico */
				 perror("open");
				 exit(3);
			 }
		} 
		else {
			/* Chiudo il file, che a questo punto esiste.
			 * Lasciandolo aperto, causeremmo un resource
			 * leak, che va evitato. */
			close(fd);
					
			/* Creo un figlio per visualizzare l'anteprima */
			pid = fork();
			if ( pid < 0) {
				perror("fork");
				exit(4);
			} 
			else if (pid == 0) {
				/* Figlio */
				printf("\nAnteprima del file %s:\n", nome);
				execlp("head", "head", "-n", argv[1], nome, (char *)0);
				
				perror("exec");
				exit(5);
			}
			/* Padre: aspetto che il figlio termini */
			wait(&status);
		}
			
		printf("\nInserisci il nome del file di cui visualizzare "
							"l'anteprima (\"fine\" per uscire): ");
		scanf("%s", nome);
	}
			
	/* Esco senza errori */
	return 0;
}
