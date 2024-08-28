#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 4096

const char *servizio = "50000";

void handler(int signo)
{
        int status;

        (void)signo; /* per evitare warning */

        /* eseguo wait non bloccanti finché ho dei figli terminati */
        while (waitpid(-1, &status, WNOHANG) > 0)
                continue;
}

int autorizza(const char *username, const char *password)
{
        (void)username; /* per evitare warning */
        (void)password; /* per evitare warning */

        return 1;
}

int main(void)
{
        int cc, err, on, sd;
        struct addrinfo hints, *res;
        struct sigaction sa;

        sigemptyset(&sa.sa_mask);
        /* uso SA_RESTART per evitare di dover controllare esplicitamente se
         * accept è stata interrotta da un segnale e in tal caso rilanciarla
         * (si veda il paragrafo 21.5 del testo M. Kerrisk, "The Linux
         * Programming Interface") */
        sa.sa_flags   = SA_RESTART;
        sa.sa_handler = handler;

        if (sigaction(SIGCHLD, &sa, NULL) == -1) {
                perror("sigaction");
                exit(EXIT_FAILURE);
        }

        memset(&hints, 0, sizeof(hints));
        hints.ai_family   = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags    = AI_PASSIVE;

        err = getaddrinfo(NULL, servizio, &hints, &res);
        if (err != 0) {
                fprintf(stderr, "Errore gai: %s\n", gai_strerror(err));
                exit(EXIT_FAILURE);
        }

        sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (sd < 0) {
                /* fprintf(stderr, "socket: %s\n", strerror(errno)); */
                perror("socket");
                exit(EXIT_FAILURE);
        }

        on = 1;
        if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0){
                perror("setsockopt");
                exit(EXIT_FAILURE);
        }

        cc = bind(sd, res->ai_addr, res->ai_addrlen);
        if (cc < 0) {
                perror("bind");
                exit(EXIT_FAILURE);
        }

        cc = listen(sd, SOMAXCONN);
        if (cc < 0) {
                perror("listen");
                exit(EXIT_FAILURE);
        }

        for (;;) {
                int pid, ns;

                ns = accept(sd, NULL, NULL);
                if (ns < 0) {
                        /* anche se uso SA_RESTART, è sempre bene controllare il caso EINTR */
                        if (errno == EINTR)
                                continue;
                        perror("accept");
                        exit(EXIT_FAILURE);
                }

                pid = fork();
                if (pid < 0) {
                        perror("fork");
                        exit(EXIT_FAILURE);
                } else if (pid == 0) {
                        /* FIGLIO */
                        char username[BUFSIZE];
                        char password[BUFSIZE];
                        char categoria_macchine[BUFSIZE];
                        const char *ack = "ACK\n";
                        const char *auth_denied = "Utente non autorizzato!\n";
                        int pid_n1, pid_n2;
                        int pipe_n1n2[2], pipe_n2f[2];

                        /* molto importante */
                        close(sd);

                        memset(username, 0, sizeof(username));
                        cc = read(ns, username, sizeof(username)-1);
                        if (cc < 0) {
                                perror("read");
                                exit(EXIT_FAILURE);
                        }

                        cc = write(ns, ack, strlen(ack));
                        if (cc < 0) {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }

                        memset(password, 0, sizeof(password));
                        cc = read(ns, password, sizeof(password)-1);
                        if (cc < 0) {
                                perror("read");
                                exit(EXIT_FAILURE);
                        }

                        if (autorizza(username, password) != 1) {
                                /* restituisco messaggio di errore */
                                cc = write(ns, auth_denied, strlen(auth_denied));
                                if (cc < 0) {
                                        perror("write");
                                        exit(EXIT_FAILURE);
                                }
                                /* il figlio ha svolto correttamente il servizio, e ora termina */
                                exit(EXIT_SUCCESS);
                        }

                        /* se il flusso di controllo arriva qui vuol dire che il client è autorizzato */
                        cc = write(ns, ack, strlen(ack));
                        if (cc < 0) {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }

                        memset(categoria_macchine, 0, sizeof(categoria_macchine));
                        cc = read(ns, categoria_macchine, sizeof(categoria_macchine)-1);
                        if (cc < 0) {
                                perror("read");
                                exit(EXIT_FAILURE);
                        }

                        cc = pipe(pipe_n1n2);
                        if (cc < 0) {
                                perror("pipe");
                                exit(EXIT_FAILURE);
                        }

                        pid_n1 = fork();
                        if (pid_n1 < 0) {
                                perror("fork");
                                exit(EXIT_FAILURE);
                        } else if (pid_n1 == 0) {
                                /* NIPOTE 1 */
                                char db_file[BUFSIZE * 2];

                                /* Chiudo file descriptor inutilizzati */
                                close(ns);
                                close(pipe_n1n2[0]);

                                /* Redirigo stdout su pipe_n1n2 */
                                close(1);
                                if (dup(pipe_n1n2[1]) < 0) {
                                        perror("dup");
                                        exit(EXIT_FAILURE);
                                }
                                close(pipe_n1n2[1]);

                                /* In alternativa a snprintf:
                                chdir("/var/local/macchine_caffé");
                                strcpy(db_file, categoria_macchine);
                                strcat(db_file, ".txt");
                                */
                                /* snprintf(db_file, sizeof(db_file), "/var/local/macchine_caffé/%s.txt", categoria_macchine); */
                                snprintf(db_file, sizeof(db_file), "%s.txt", categoria_macchine);

                                execlp("cut", "cut", "-f", "1,3,4", "-d", ",", db_file, NULL);
                                exit(EXIT_FAILURE);
                        }

                        cc = pipe(pipe_n2f);
                        if (cc < 0) {
                                perror("pipe");
                                exit(EXIT_FAILURE);
                        }

                        pid_n2 = fork();
                        if (pid_n2 < 0) {
                                perror("fork");
                                exit(EXIT_FAILURE);
                        } else if (pid_n2 == 0) {
                                /* NIPOTE 2 */

                                /* Chiudo file descriptor inutilizzati */
                                close(ns);
                                close(pipe_n1n2[1]);
                                close(pipe_n2f[0]);

                                /* Redirigo stdin da pipe_n1n2 */
                                close(0);
                                if (dup(pipe_n1n2[0]) < 0) {
                                        perror("dup");
                                        exit(EXIT_FAILURE);
                                }
                                close(pipe_n1n2[0]);

                                /* Redirigo stdout su pipe_n2f */
                                close(1);
                                if (dup(pipe_n2f[1]) < 0) {
                                        perror("dup");
                                        exit(EXIT_FAILURE);
                                }
                                close(pipe_n2f[1]);

                                execlp("sort", "sort", "-r", "-n", NULL);
                                exit(EXIT_FAILURE);
                        }

                        /* FIGLIO */

                        /* Chiudo file descriptor inutilizzati */
                        close(pipe_n1n2[0]);
                        close(pipe_n1n2[1]);
                        close(pipe_n2f[1]);

                        /* Redirigo stdin da pipe_n2f */
                        close(0);
                        if (dup(pipe_n2f[0]) < 0) {
                                perror("dup");
                                exit(EXIT_FAILURE);
                        }
                        close(pipe_n2f[0]);

                        /* Redirigo stdout su socket ns */
                        close(1);
                        if (dup(ns) < 0) {
                                perror("dup");
                                exit(EXIT_FAILURE);
                        }
                        close(ns);

                        execlp("head", "head", "-n", "10", NULL);
                        exit(EXIT_FAILURE);
                }

                /* PADRE */
                close(ns);
        }

        /* in caso... */
        close(sd);

        return 0;
}

