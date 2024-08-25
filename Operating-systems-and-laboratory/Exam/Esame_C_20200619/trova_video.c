#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <wait.h>

#define DIM 100

/* contatore delle richieste */
static volatile sig_atomic_t counter=0;

/* gestore per il segnale SIGINT */
void sigint_handler(int signal) {
	printf("\nCTRL-C ricevuto:\tSono state servite %d richieste\n", counter);
	exit(0);
}

int main(int argc, char* argv[]) {
	char argomento[20], data[9], to_open[DIM];
	int pid1, pid2, fd, status;
	int pipe_sort[2];
	struct sigaction s_int;
	
	/* Controllo numero degli argomenti */
	if(argc!=2) {
		fprintf(stderr,"Errore: Uso %s dir\n",argv[0]);
		exit(1);
	}
	/* dir deve essere un nome relativo di directory */
	if(argv[1][0] == '/') {
		fprintf(stderr,"Errore: dir deve essere un nome relativo di directory");
		exit(1);
	}
	/* controllo esistenza directory */
	if((fd=open(argv[1], O_DIRECTORY))<0) {
		perror("Errore nell'apertura di dir");
		exit(2);
	}
	close(fd);
	
	/* imposto l'handler per il segnale SIGINT */
	sigemptyset(&s_int.sa_mask);
	s_int.sa_flags=0;
	s_int.sa_handler=sigint_handler;
	sigaction(SIGINT, &s_int, NULL);

	while(1) { /* Termina solo per il Ctrl-C */
        printf("Inserire tipo video:\n");
        scanf("%s", argomento);
		printf("Inserire data in formato YYYYMM:\n");
		scanf("%s",data);
		/* costruisco il nome assoluto del file utilizzando sprintf, il file ha estensione .txt */
		sprintf(to_open, "%s/%s.txt", argv[1],data);
		if((fd=open(to_open, O_RDONLY))<0) {
			fprintf(stderr,"Errore nell'apertura del file %s\n",to_open);
            exit(3);
		}
		close(fd);
		
        /* creazione della pipe, che deve essere creata prima dei due processi figli in modo che riescano a utilizzarla */
		if(pipe(pipe_sort)<0) {
			perror("Errore: pipe");
			exit(3);
		}
		/* creazione del processo figlio P1, si occuperà di filtrare i video di interesse */
		if((pid1=fork())<0) {
			perror("Errore: fork() per processo P1");
			exit(4);
		}
		if(pid1==0) {
		/* chiusura canali pipe non neccessari e redirezione dell'output del comando grep su pipe_sort */
			close(pipe_sort[0]);
			close(1);
			dup(pipe_sort[1]);
			close(pipe_sort[1]);
			execlp("grep", "grep", argomento, to_open, (char *)0);
			perror("Errore: grep ");
            exit(5);
		}
		/* sono nel processo Padre, creo il processo figlio P2 che si occuperà di ordinare i video in ordine decrescente rispetto alle visualizzazioni */
		if((pid2=fork())<0) {
			perror("Errore: fork() per processo P2");
			exit(6);
		}
		if(pid2==0) {
			/* chiusura canali pipe non neccessari e redirezione. P2 esegue sort sui dati provenienti dall'esecuzione di grep*/
			close(pipe_sort[1]);
			close(0);
			dup(pipe_sort[0]);
			close(pipe_sort[0]);
			/* l'ordinamento deve essere decrescente. In questo caso il -n non servirebbe */
			execlp("sort", "sort", "-r", "-n", (char*)0);
			perror("Errore: sort ");
			exit(4);
		}

		/* sono ancora nel Padre. Incremento le richieste servite, chiudo i canali delle pipe non neccessari e aspetto la terminazione dei figli */
		close(pipe_sort[0]);
		close(pipe_sort[1]);
		wait(&status);
		wait(&status);
		counter++;
    }
	return 0;
}
