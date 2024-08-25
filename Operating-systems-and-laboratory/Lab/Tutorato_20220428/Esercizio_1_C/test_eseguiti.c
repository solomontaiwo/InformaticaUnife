//test_eseguiti dir data
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define DIM_REF 100
#define DIM_RES 1024

static volatile sig_atomic_t count = 0;

void gestore(){
    printf("\nCTRL-C! bytes totali ricevuti %d\n", count);
    exit(0);
}

int main(int argc, char const *argv[])
{
    /* code */
    int pid, p0p1[2], p0p2[2], fd, status, nread, nwrite;
    char ref[DIM_REF], res[DIM_RES], filepath[DIM_REF];

    if (argc != 3){
        printf("Uso: %s <dir> <data>", argv[0]);
        exit(1);
    }

    if (argv[1][0] == '/'){
        printf("%s deve essere relativo", argv[1]);
        exit(2);
    }

    fd = open(argv[1], O_DIRECTORY);
    if(fd < 0){
        perror("PO: open");
        exit(3);
    }
    close(fd);

    sprintf(filepath, "%s/%s.txt", argv[1], argv[2]);
    fd = open(filepath, O_RDONLY);
    if(fd < 0){
        perror("PO: open");
        exit(4);
    }
    close(fd);

    signal(SIGINT, gestore);

    if(pipe(p0p1)<0){
        perror("P0: pipe p0p1");
        exit(5);
    }

    if(pipe(p0p2)<0){
        perror("P0: pipe p0p2");
        exit(6);
    }

    if( (pid = fork()) < 0 ){
        perror("P0: fork");
        exit(7);
    }

    if(pid == 0){
        // sono il figlio, P1

        signal(SIGINT, SIG_DFL);

        close(p0p1[1]);

        close(p0p2[0]);

        while(1){
            nread = read(p0p1[0], ref, sizeof(ref) - 1);
            if(nread <0 ){
                perror("P1 read");
                exit(8);
            }
            ref[nread] = '\0';

            pid = fork();
            if(pid < 0){
                perror("P1 fork");
                exit(9);
            }

            if ( pid == 0 ){
                // nipote P2
                close(p0p1[0]);

                close(1);
                dup(p0p2[1]);
                close(p0p2[1]);

                execlp("grep", "grep", ref, filepath, (char *) 0);
                perror("P2 exec");
                exit(10);

            }

            wait(&status);
        }

    }

    close(p0p1[0]);

    close(p0p2[1]);

    // sono il padre P0
    while(1){
        printf("Inserire nome refertatore: ");
        scanf("%s", ref);

        nwrite = write(p0p1[1], ref, strlen(ref) + 1);
        if(nwrite != (strlen(ref) + 1)){
            perror("P0 write");
            exit(11);
        }

        nread = read(p0p2[0], res, sizeof(res) - 1);
        if(nread <0 ){
            perror("P0 read");
            exit(12);
        }
        res[nread] = '\0';

        printf("%s\n", res);
        count += nread;
    }


    return 0;
}
