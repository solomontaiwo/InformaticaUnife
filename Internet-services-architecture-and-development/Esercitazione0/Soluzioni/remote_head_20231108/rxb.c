#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "rxb.h"

void rxb_init(struct rx_buffer *buf, int buf_size)
{
        buf->buffer = malloc(buf_size);
        if (buf->buffer == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
        }
        buf->bytes_received = 0;
        buf->size = buf_size;
}

void rxb_destroy(struct rx_buffer *buf)
{
        free(buf->buffer);
        buf->bytes_received = 0;
        buf->size = 0;
}

int rxb_readline(struct rx_buffer *buf, int sock, void *dest_buf, size_t *dest_len)
{
        uint8_t *dest = dest_buf;
        uint8_t *term_ptr = NULL;
        ssize_t cc;

        /* Leggo i dati in un buffer */
        do {
                int left;

                /* Controllo se ho ricevuto il terminatore '\n' */
                term_ptr = memchr(buf->buffer, '\n', buf->bytes_received);
                if (term_ptr != NULL) {
                        /* Calcolo quanti dati devo copiare */
                        size_t to_copy = term_ptr - buf->buffer;

                        /* Verifico che dest sia sufficientement grande */
                        if (*dest_len < to_copy) {
                                fprintf(stderr, "Buffer too small!\n");
                                close(sock);
                                exit(EXIT_FAILURE);
                        }

                        /* Copio dati da buffer a dest e aggiorno dest_len */
                        memcpy(dest, buf->buffer, to_copy);
                        *dest_len = to_copy;

                        /* Aggiorno contatori e, se necessario, resetto buffer */
                        buf->bytes_received -= (to_copy + 1);
                        if (buf->bytes_received > 0) {
                                memmove(buf->buffer, term_ptr + 1, buf->bytes_received);
                        }

                        break;
                }

                left = buf->size - buf->bytes_received;
                if (left == 0) {
                        /* Client che malfunziona - inviato messaggio di
                         * dimensioni maggiori di MAX_REQUEST_SIZE */
                        fprintf(stderr, "Request too long!\n");
                        close(sock);
                        exit(EXIT_SUCCESS);
                };

                cc = read(sock, buf->buffer + buf->bytes_received, left);
                if (cc == 0)
                        return -1;
                if (cc < 0) {
                        fprintf(stderr, "Input error!\n");
                        perror("read");
                        close(sock);
                        exit(EXIT_FAILURE);
                }
                buf->bytes_received += cc;

        } while (1);

        return 0;
}

int rxb_read_bytes(struct rx_buffer *buf, int sock)
{
        int cc = read(sock, buf->buffer + buf->bytes_received, 
		      buf->size - buf->bytes_received);
        if (cc == 0)
                return -1;
        if (cc < 0) {
                fprintf(stderr, "Input error!\n");
                perror("read");
                close(sock);
                exit(EXIT_FAILURE);
        }
        buf->bytes_received += cc;
        return cc;
}

size_t rxb_size(const struct rx_buffer *buf)
{
        return buf->size;
}

size_t rxb_available(const struct rx_buffer *buf)
{
        return buf->bytes_received;
}

uint8_t *rxb_peek(const struct rx_buffer *buf)
{
        return buf->buffer;
}

int rxb_drop_bytes(struct rx_buffer *buf, size_t num_bytes)
{
        if (num_bytes > buf->bytes_received) {
                /* nonsense request */
                return -1;
        }

        memmove(buf->buffer, buf->buffer + num_bytes, buf->bytes_received - num_bytes);
        buf->bytes_received -= num_bytes;

        return 1;
}
