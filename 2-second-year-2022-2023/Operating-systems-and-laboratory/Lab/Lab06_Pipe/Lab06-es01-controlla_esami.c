#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define DIM 80

int main (int argc, char **argv) {

	int p1p2[2];
	char matricola[DIM];
	int pid1, pid2, fd, status;
	
	/* Controllo numero argomenti */
	if (argc != 2) {
		fprintf(stderr, "Uso: ./controlla_esami <file_dati> \n");
		exit(1);
	}
	
	/* argv[1] è un nome assoluto di file */
	if (argv[1][0] != '/') {
		fprintf(stderr, "Il primo argomento deve essere un nome assoluto di file\n");
		exit(2);
	}

	/* Per controllare se il file esiste, provo ad aprirlo */
	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		fprintf(stderr, "Il file %s non esiste\n", argv[1]);
		exit(3);
	}
	/* Chiudo il file, che a questo punto sono certo che esista */
	close(fd);

	printf("Inserisci la matricola da cercare: ");
	scanf("%s", matricola);

	while (strcmp(matricola, "fine")) {
		
		/* Creazione della pipe */
		if(pipe(p1p2) < 0) {  /* pipe tra p1 --> p2 */
			perror("pipe p1 --> p2");
			exit(4);
		}
		
		/* Genero P1 */
		if ((pid1 = fork()) < 0){
			perror("fork p1");
			exit(5);
		}
		if (pid1 == 0) { /* figlio P1 */
			/* Chiudo i canali non necessari */
			close(p1p2[0]);
			
			/* Redirezione stdout */
			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);
			
			/* exec() */
			execlp("grep", "grep", matricola, argv[1], (char*)0);
			perror("execlp grep");
			exit(6);
		} 
		
		/* P0 padre: genero P2 */
		if ((pid2 = fork()) < 0) { 
			perror("fork p2");
			exit(7);
		}
		if (pid2 == 0) { /* figlio P2 */
			/* Chiudo i canali non necessari */
			close(p1p2[1]);
			
			/* Redirezione stdin */
			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);
			
			/* exec() */
			execlp("wc", "wc", "-l", (char*)0);
			perror("execlp wc");
			exit(8);
		}
		
		/* P0 padre */
		/* Chiudo i canali non necessari */
		close(p1p2[0]);
		close(p1p2[1]);
		
		/* Attendo la morte dei figli */
		wait(&status);
		wait(&status);
		
		/* Chiedo una nuova matricola */
		printf("Inserisci la matricola da cercare: ");
		scanf("%s", matricola);
	}

	return 0;
}
