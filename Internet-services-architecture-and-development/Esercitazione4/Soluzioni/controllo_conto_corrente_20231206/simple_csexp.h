#ifndef UNIFE_SIMPLE_CSEXP_H
#define UNIFE_SIMPLE_CSEXP_H

#include <stdint.h>
#include "rxb.h"

int simple_csexp_read_message(struct rx_buffer *rxb, int fd, char ***out, size_t *out_len);

#endif /* UNIFE_SIMPLE_CSEXP_H */
