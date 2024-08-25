#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 80

static volatile sig_atomic_t timeout;

void gestore_ctrlc (int segnale){
	printf("Ricevuto ctrl-C, timeout e terminazione \n");
	alarm(timeout);
}

void gestore_alarm (int segnale){
	printf("Terminazione \n");
	kill(0, SIGKILL);
}

int main(int argc,char **argv) {
	
	int i, j, status, nread, Nproc, p0pi[SIZE][2], pip0[SIZE][2];
	char buff[SIZE], nomefile[SIZE];
	
	if(argc != 2) {
		printf("Errore! Uso: %s timeout\n", argv[0]);
		exit(1);
	}
	
	/* inserire parte di controllo argomenti ..... */
	signal(SIGINT, gestore_ctrlc);
	signal(SIGALRM, gestore_alarm);
	
	Nproc=argc-2;
	timeout=atoi(argv[1]);
	for(i=0;i<Nproc;i++) {
		pipe(p0pi[i]);
		pipe(pip0[i]);
	}
	
	for(i=0;i<Nproc;i++) {
		if(fork()==0) { // Figlio Pi
		
			signal(SIGINT, SIG_IGN);
			signal(SIGALRM, SIG_IGN);
			
			for(j=0;j<Nproc;j++){
				if(j!=i){
					close(p0pi[j][0]);
					close(p0pi[j][1]);
					close(pip0[j][0]);
					close(pip0[j][1]);
				}
				close(p0pi[i][1]);
				close(pip0[i][0]);
			}
			
			while(1) {
				nread=read(p0pi[i][0], nomefile, SIZE);
				if (fork()==0) {
					
					close(1);
					dup(pip0[i][1]);
					
					close(pip0[i][1]);
					close(p0pi[i][0]);
					
					execl("/bin/grep","grep","-c",argv[i+2],nomefile,(char *) 0);
				}
				wait(&status);
			}
			exit(1);
		} // fine figlio i
	} // fine for
	
	// Ancora padre P0
	for(i=0;i<Nproc;i++){
		close(p0pi[i][0]);
		close(pip0[i][1]);
	}
	
	while(1) {
		printf("Inserire il nome del file:\n");
		scanf("%s",nomefile);
		for(i=0;i<Nproc;i++)
			write(p0pi[i][1], nomefile, strlen(nomefile)+1);
		
		for(i=0;i<Nproc;i++) {
			nread=read(pip0[i][0], buff, SIZE);
			buff[nread-1]='\0';
			printf("Padre: la stringa %s compare nel file %s %s volte\n", argv[i+2], nomefile, buff);
		}
	}
	
} // fine main
