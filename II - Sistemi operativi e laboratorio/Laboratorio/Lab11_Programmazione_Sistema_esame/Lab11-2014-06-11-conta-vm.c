#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define S_DIM 128
#define S_PATH 256
#define S_RES 16

typedef int pipe_t[2];
static volatile sig_atomic_t counter = 0;

void handler(int s) {
	printf("Ricevuto interrupt da tastiera; servite %d richieste...\n", counter);
	exit(0);
}

int main(int argc, char **argv) {
	int pid, status, fd;
	ssize_t nread;
	pipe_t p1p2, p2p0;
	char cloud_provider[S_DIM], application_name[S_DIM],
	file_path[S_PATH], result_str[S_RES];
	
	// Controllo argomenti
	if(argc != 2) {
		printf("Errore! Uso: %s <dir_name>\n", argv[0]);
		exit(1);
	}
	if(argv[1][0] != '/') {
		printf("Errore! Il nome specificato non e' un direttorio assoluto.\n");
		exit(2);
	}
	if((fd = open(argv[1], O_DIRECTORY)) < 0) {
		perror("Il nome specificato non è una directory.\n");
		exit(3);
	}
	close(fd);
	
	// Installazione del gestore del SIGINT
	signal(SIGINT, handler);
	
	printf("Inserire il nome di un Cloud Provider, o \"fine\" per uscire\n");
	scanf("%s", cloud_provider);
	
	while(strcmp(cloud_provider, "fine")) {
		sprintf(file_path, "%s/%s.txt", argv[1], cloud_provider);
		if((fd = open(file_path, O_RDONLY)) < 0) {
			if(errno == ENOENT) {
				printf("Il file che contiene i dati relativi al Cloud Provider \"%s\" non esiste.\n", cloud_provider);
				printf("Inserire il nome di un Cloud Provider, o \"fine\" per uscire:\n");
				scanf("%s", cloud_provider);
				continue;
			}
			perror("Errore tentando di aprire il file che contiene i dati per il Cloud Provider specificato.\n");
			exit(4);
		}
		close(fd);
		
		printf("Inserire il nome dell'applicazione:\n");
		scanf("%s", application_name);
		
		if(pipe(p1p2) < 0) {
			perror("pipe() p1p2");
			exit(5);
		}
		if((pid = fork()) < 0) {
			perror("fork() P1");
			exit(6);
		}
		else if(pid == 0) {
			// Figlio P1
			// Il figlio termina(default) in caso riceva il SIGINT
			signal(SIGINT, SIG_DFL); 
			close(p1p2[0]);
			
			// Redirezione standard output
			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);
			execlp("grep", "grep", application_name, file_path,(char*) 0);
			perror("P1; execlp");
			exit(7);
		}
		
		// P0
		close(p1p2[1]);
		if(pipe(p2p0) < 0) {
			perror("pipe() p2p0");
			exit(8);
		}
		if((pid = fork()) < 0) {
			perror("fork() P2");
			exit(9);
		}
		else if(pid == 0) {
			// Figlio P2
			// Il figlio termina(default) in caso riceva il SIGINT
			signal(SIGINT, SIG_DFL); 

			close(p2p0[0]);
			// Redirezione std in e std out
			close(0);
			dup(p1p2[0]);
			
			close(p1p2[0]);
			close(1);
			dup(p2p0[1]);
			
			close(p2p0[1]);
			execlp("grep", "grep", "-c", "operativa",(char*) 0);
			perror("P2; execlp");
			exit(10);
		}
		// P0
		close(p1p2[0]);
		close(p2p0[1]);
		
		// lettura risultato della grep da pipe
		nread = read(p2p0[0], result_str, S_RES-1);
		close(p2p0[0]);
		result_str[nread] = '\0';
		
		// Scrittura su file_risultati
		printf("Cloud Provider: %s\nApplicazione: %s\nIstanze Operative: %s\n\n",
		cloud_provider, application_name, result_str);
		++counter;
		
		// Zombies
		wait(&status);
		wait(&status);
		printf("Inserire il nome di un Cloud Provider, o \"fine\" per uscire:\n");
		scanf("%s", cloud_provider);
	} // fine while
	
	printf("Numero di richieste servite: %u\n", counter);
	return 0;
}