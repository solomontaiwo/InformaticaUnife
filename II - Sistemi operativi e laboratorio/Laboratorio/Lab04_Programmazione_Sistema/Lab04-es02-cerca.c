#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    
	int pid, fd, status, i;

    /* Controllo il numero degli argomenti */
    if (argc < 3) {
        fprintf(stderr, "Uso: ./cerca <nomefile> <stringa1> ... <stringaN> \n");
        exit(1);
    }
	
	/* Creo (sovrascrivo se esiste) e chiudo il file di conteggio.txt */
	fd = open("conteggio.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0) {
		perror("Errore nella creazione del file di conteggio, termino\n");
		exit(2);
	}
	/* chiudo il file */
	close(fd);

	/* Creo i figli */
	for(i = 2; i < argc; i++) {
		pid = fork();
		if ( pid < 0) {
		   /* Errore */
		   perror("fork");
		   exit(3);
		}
		else if (pid == 0) {
			/* Figlio */
			char log[256];
			
			/* apro il file in append */
			fd = open("conteggio.txt", O_WRONLY | O_APPEND);
			
			/* creo il log dell'operazione di conteggio */
			sprintf(log, "%s %s\n", argv[1], argv[i]);
			
			/* scrivo il log su file */
			write(fd, log, strlen(log));
			
			/* chiudo il file */
			close(fd);

			printf("\nNum volte che si ripete la stringa %s:\n", argv[i]);
			/* chiamata a: grep -c stringa nomefile */
			execlp("grep","grep","-c", argv[i], argv[1], (char *)0);
			
			perror("exec");
			exit(4);
		}
		else {
			/* Padre - Attendo la terminazione del figlio */
			wait(&status);
		}
	} // fine for
	
	/* Esco senza errori */
	return 0;
}
