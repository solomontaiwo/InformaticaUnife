#ifndef UNIFE_RXB_H
#define UNIFE_RXB_H

#include <stdint.h>
#include <sys/types.h>

typedef struct rx_buffer {
        uint8_t *buffer;
        /* Queste variabili tracciano rispettivamente la dimensione del buffer
         * e il numero di byte usati */
        size_t size;
        int bytes_received; 
} rxb_t;

void rxb_init(struct rx_buffer *buf, int buf_size);
void rxb_destroy(struct rx_buffer *buf);
int rxb_readline(struct rx_buffer *buf, int sock, void *dest_buf, size_t *dest_len);
int rxb_read_bytes(struct rx_buffer *buf, int sock);
size_t rxb_size(const struct rx_buffer *buf);
size_t rxb_available(const struct rx_buffer *buf);
uint8_t *rxb_peek(const struct rx_buffer *buf);
int rxb_drop_bytes(struct rx_buffer *buf, size_t num_bytes);

#endif /* UNIFE_RXB_H */
