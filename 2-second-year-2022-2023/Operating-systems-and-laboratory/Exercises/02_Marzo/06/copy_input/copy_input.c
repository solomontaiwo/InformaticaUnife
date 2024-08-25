#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // per fork
#include <string.h> // per strcmp
#include <fcntl.h> // descrittore dei flag per open()

int main(int argc, char **argv)
{
	int fd;
	char buff[1024];

	// Controllo degli argomenti
	if (argc != 2)
	{
		fprintf(stderr, "Usage: copyinput filename\n");
		exit(1);
	}

	/* Creo il file utilizzando la system call open, con relativi flag e permessi
	0644 rw-r--r--- */
	fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
	if (fd < 0) {
		fprintf(stderr, "Error creating file %s\n", argv[1]);
		exit(2);
	}

	/* fgets preleva una linea da uno stream, in alternativa si può leggere una stringa
	senza spazi con scanf */
	printf("Inserisci una stringa: \n");
	fgets(buff, 1024, stdin);

	// se uso fgets avrò in buff anche il carattere di new line
	while (strcmp(buff, "fine\n") != 0) {
		write(fd, buff, strlen(buff));
		printf("Inserisci un'altra stringa (fine per uscire):\n");
		fgets(buff, 1024, stdin);
	}

	close(fd);

	return 0;

}