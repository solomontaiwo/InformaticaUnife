#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {

	int fd;

	char buff[1024];

	//Controllo degli argomenti
	if (argc != 2) {
		fprintf(stderr, "Usage: copy_input filename\n");
		exit(1);
	}

	// Creo il file utilizzando la system call open, con relativi flag 
	// e permessi 0644 rw-r--r--
	fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0) {
		fprintf(stderr, "Error creating file %s\n", argv[1]);
		exit(2);
	}

	// fgets e' una funzione molto comoda in quanto preleva una linea
    // da uno stream (ad esempio stdin)
    // alternativamente posso leggere una stringa senza spazi con scanf
	printf("Inserisci una stringa: \n");
	fgets(buff, 1024, stdin);

	// se uso fgets avro' in buff anche il carattere di new line
    // se uso scanf faccio il controllo solo con "fine" (senza \n) 
	while (strcmp(buff, "fine\n") != 0) {
		write(fd, buff, strlen(buff));
		printf("Inserisci un'altra stringa (fine per uscire):\n");
		fgets(buff, 1024, stdin);
	}

	close(fd);

	return 0;
}
