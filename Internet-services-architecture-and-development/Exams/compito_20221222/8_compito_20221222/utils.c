#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

/* For sendfile */
#if __APPLE__
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#elif __linux__
#include <sys/sendfile.h>
#endif


ssize_t write_all(int fd, const void *vptr, size_t n)
{
        size_t remaining;
        ssize_t cc;
        const uint8_t *ptr;

        ptr = vptr;
        remaining = n;
        while (remaining > 0) {
                if ((cc = write(fd, ptr, remaining)) <= 0) {
                        if (cc < 0 && errno == EINTR)
                                cc = 0;
                        else
                                return -1;
                }

                remaining -= cc;
                ptr += cc;
        }
        return n;
}

ssize_t read_all(int fd, void *vptr, size_t n)
{
	size_t remaining;
	ssize_t cc;
        uint8_t *ptr;

        ptr = vptr;
        remaining = n;
        while (remaining > 0) {
                if ((cc = read(fd, ptr, remaining)) < 0) {
                        if (errno == EINTR)
                                cc = 0;
                        else
                                return -1;
                } else if (cc == 0) /* EOF */
                        break;

                remaining -= cc;
                ptr += cc;
        }
        return (n - remaining);
}


/* sendfile(2) è una system call non standard, che ha un formato diverso sotto
 * Linux e sotto MaxOS (che ricalca FreeBSD). Questa funzione prova a
 * realizzarne una versione più semplice ma portabile. 
 *
 * Due assunzioni di lavoro: 
 * 1) si vuole mandare tutto il contenuto del file;
 * 2) l'IO pointer di fd al momento della chiamata a portable_sendfile è 0
 *    (ovverosia a inizio file). */
int portable_sendfile(int fd, int ns)
{
#if __linux__
	/* Caso Linux */
	off_t off = 0;
        off_t response_len = lseek(fd, 0, SEEK_END);
	return sendfile(ns, fd, &off, response_len);
#elif __APPLE__
	/* Caso MacOS */
	off_t off = 0;
        return sendfile(fd, ns, (off_t)0, &off, NULL, 0);
#else
	/* Non siamo né sotto Linux né sotto MaxOS: non usiamo sendfile(2) ma
	 * un ciclo di read da file e write da socket. Decisamente meno
	 * efficiente, ma tant'è... */
	int nread, err; uint8_t buffer[4096];
	while ((nread = read(fd, buffer, sizeof(buffer))) > 0) {
		if ((err = write_all(ns, buffer, nread)) < 0) {
			return err;
		}
	}
	return nread;
#endif
}
