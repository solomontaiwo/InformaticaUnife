#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #include <sys/types.h> */
/* #include <sys/stat.h> */
/* #include <fcntl.h> */
#include <unistd.h>
#include "rxb.h"
#include "utils.h"

typedef enum {
        START_MESSAGE,
        READ_LENGTH_START,
        READ_LENGTH_CONTINUE
} parser_state_t;

#define MAX_TOKEN_SIZE 4096
#define MAX_TOKENS 16

int simple_csexp_read_message(struct rx_buffer *rxb, int fd, char ***out, size_t *out_len)
{
        parser_state_t ps = START_MESSAGE;
        unsigned int string_index = 0;
        int next_string_length = -1;
        char *c;
        char current_token[MAX_TOKEN_SIZE] = {0};
        char *d = current_token;
        size_t bytes_left;
        size_t processed = 0;
	int ret = -10;
	char **res;

	res = (char **)calloc(sizeof(char *) * MAX_TOKENS, 1);
	if (res == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}

        /* read some data */
        if (rxb_available(rxb) == 0) {
                int cc = rxb_read_bytes(rxb, fd);
                if (cc <= 0) {
                        /* I/O error or EOF */
                        return -2;
                }
        }
        /* initialize c and bytes_left */
        c = (char *)rxb_peek(rxb);
        bytes_left = rxb_available(rxb);

        while (1) {
                /* read more data if needed */
                if (bytes_left == 0) {
                        int cc = rxb_read_bytes(rxb, fd);
                        if (cc <= 0) {
                                /* I/O error or EOF */
                                ret = -3;
                                goto CLEANUP;
                        }
                        /* reinitialize c and bytes_left */
                        c = (char *)rxb_peek(rxb);
                        bytes_left = rxb_available(rxb);
                }

                switch(ps) {
                        case START_MESSAGE:
                                /* printf("START_MESSAGE w/ *c == '%c'\n", *c); */
                                if (*c != '(') {
                                        ret = -4;
                                        goto CLEANUP;
                                }

                                ps = READ_LENGTH_START;
                                break;

                        case READ_LENGTH_START:
                                /* printf("READ_LENGTH_START w/ *c == '%c'\n", *c); */
                                if (*c == ')') {
					/* printf("dropping %lu bytes\n", processed + 1); */
                                        /* drop the bytes in the buffer that we already used */
                                        /* rxb_drop_bytes(rxb, available - unprocessed); */
                                        rxb_drop_bytes(rxb, processed + 1);

					/* printf("string_index %u\n", string_index); */

                                        /* set out and out_len */
					*out = res;
                                        *out_len = string_index;

                                        /* we finished reading the message;
                                         * let's return the number of
                                         * unprocessed characters left in the
                                         * buffer */
                                        return rxb_available(rxb);
                                } else if (*c < '1' || *c > '9') { /* first digit can't be 0 */
                                        /* not a digit */
                                        ret = -5;
                                        goto CLEANUP;
                                }

				/* copy character into current_token buffer */
                                *d++ = *c;

                                ps = READ_LENGTH_CONTINUE;
                                break;

                        case READ_LENGTH_CONTINUE:
                                /* printf("READ_LENGTH_CONTINUE w/ *c == '%c'\n", *c); */
                                if (*c == ':') {
                                        /* get next string length */
                                        next_string_length = atoi(current_token);
                                        /* printf("READ_LENGTH_CONTINUE w/ next_string_length == '%d'\n", next_string_length); */

                                        /* extract string */
					char *string = calloc(1, next_string_length + 1);
                                        if (string == NULL) {
                                                ret = -6;
                                                goto CLEANUP;
                                        }
					/* make sure we have enough data in the buffer */
					while (bytes_left < next_string_length + 1) {
						int cc = rxb_read_bytes(rxb, fd);
						if (cc <= 0) {
							/* I/O error or EOF */
							ret = -7;
							goto CLEANUP;
						}
						/* printf("reading more data: %lu (existing)+%d (new) bytes\n", bytes_left, cc); */
						bytes_left += cc;
					}
					char *start = c + 1;
                                        memcpy(string, start, next_string_length);
					/* printf("string_index: %d\n", string_index); */
                                        res[string_index++] = string;

					/* printf("string: %s\n", string); */
					/* printf("res[%d]: %s\n", string_index-1, res[string_index-1]); */

					/* update counters */
                                        c += next_string_length;
                                        bytes_left -= next_string_length;
					processed += next_string_length;

                                        /* reset current_token */
                                        memset(current_token, 0, sizeof(current_token));
                                        d = current_token;

                                        ps = READ_LENGTH_START;
                                        break;
                                } else if (*c < '0' || *c > '9') {
                                        /* not a digit */
                                        ret = -8;
                                        goto CLEANUP;
                                }

				/* copy character into current_token buffer */
                                *d++ = *c;

                                ps = READ_LENGTH_CONTINUE;
                                break;

                        default:
                                /* unrecognized state */
                                ret = -9;
                                goto CLEANUP;
                }
		/* update counters */
		processed += 1; ++c; --bytes_left;
        }

CLEANUP:
        /* free all allocated strings */
        while (string_index > 0) {
                free(res[--string_index]);
        }
        free(res);
	*out = NULL; *out_len = 0;
        return ret;
}


