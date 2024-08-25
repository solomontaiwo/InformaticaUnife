#ifndef UNIFE_UTILS_H
#define UNIFE_UTILS_H

#include <sys/types.h>

ssize_t write_all(int fd, const void *vptr, size_t n);
ssize_t read_all(int fd, void *vptr, size_t n);
int portable_sendfile(int fd, int ns);

#endif /* UNIFE_UTILS_H */

