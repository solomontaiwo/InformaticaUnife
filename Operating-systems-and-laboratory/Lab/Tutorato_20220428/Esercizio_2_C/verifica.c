#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define SIZE 256

static volatile sig_atomic_t totRichieste;

void gestore(int segnale){
    printf("\nCTRL-C! svolti %d servizi\n", totRichieste);
    exit(0);
}

int main(int argc, char const *argv[])
{
    int status, pid1, pid2, pid3, fd;
    char tipologia[SIZE];
    int p1p2[2], p2p3[2];

    // grep luce filebollette | grep "da pagare" | sort -r -n

    if(argc < 2){
        perror ("Uso corretto: verifica <filebollette>\n");
        exit(1);
    }

    if((fd = open (argv[1], O_RDONLY)) <0 ){
        perror("file non esiste");
        exit(2);
    }

    close(fd);

    signal(SIGINT,gestore);

    printf("inserisci tipologia: ");
    scanf("%s", tipologia);
    while(strcmp(tipologia, "fine")!=0){

        if(pipe(p1p2)<0){
            perror("p1p2");
            exit(3);
        }

        pid1 = fork();
        if (pid1 < 0){
            perror("Figlio 1");
            exit(4);
        }
        if(pid1 == 0){
            // Figlio 1, P1
            close(p1p2[0]);

            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execl("/bin/grep", "grep", tipologia, argv[1], (char *) 0);
            perror("exec P1");
            exit(5);
        }

        close(p1p2[1]);

        if(pipe(p2p3)<0){
            perror("p2p3");
            exit(3);
        }

        pid2 = fork();
        if (pid2 < 0){
            perror("Figlio 2");
            exit(6);
        }
        if(pid2 == 0){
            // Figlio 2, P2

            close(p2p3[0]);

            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            close(1);
            dup(p2p3[1]);
            close(p2p3[1]);

            execl("/bin/grep", "grep", "da pagare", (char *) 0);
            perror("exec P2");
            exit(5);
        }

        close(p1p2[0]);
        close(p2p3[1]);

        pid3 = fork();
        if (pid3 < 0){
            perror("Figlio 3");
            exit(6);
        }
        if(pid3==0){
            // P3
            close(0);
            dup(p2p3[0]);
            close(p2p3[0]);

            execl("/bin/sort", "sort", "-r", "-n", (char *) 0);
            perror("exec P3");
            exit(7);
        }

        close(p2p3[0]);

        wait(&status);
        wait(&status);
        wait(&status);

        totRichieste++;

        printf("inserisci tipologia: ");
        scanf("%s", tipologia);

    }

    return 0;
}
