SOURCES := $(wildcard *.[ch])
TODAY   := $(shell date +%Y%m%d)
ARCHIVE := rstrcmp_unix_$(TODAY).zip
TARGETS := client-naive server-concurrent-naive client-lpd server-concurrent-lpd client-lpd-connreuse server-concurrent-lpd-connreuse

CFLAGS  := -std=c17 -O2 -g3 -Wall -Werror -pedantic -fsanitize=address,undefined -Wformat -Werror=format-security -Werror=array-bounds
LDFLAGS := -fsanitize=address,undefined -fpie -Wl,-pie

# If homebrew is installed, add library and include path
ifneq "$(shell brew -v)" ""
  LDFLAGS += -L$(shell brew --prefix)/lib
  CFLAGS += -I$(shell brew --prefix)/include
endif

ifeq ($(USE_LIBUNISTRING),yes)
  CFLAGS += -DUSE_LIBUNISTRING=1
  LDFLAGS += -lunistring
endif

.PHONY: clean dist

all: $(TARGETS)

# dependencies
client-lpd.o: client-lpd.c utils.h
server-concurrent-lpd.o: server-concurrent-lpd.c utils.h
client-lpd: client-lpd.o utils.o
server-concurrent-lpd: server-concurrent-lpd.o utils.o
client-lpd-connreuse.o: client-lpd-connreuse.c utils.h
server-concurrent-lpd-connreuse.o: server-concurrent-lpd-connreuse.c utils.h
client-lpd-connreuse: client-lpd-connreuse.o utils.o
server-concurrent-lpd-connreuse: server-concurrent-lpd-connreuse.o utils.o
# implicitly inferred from default
# client-naive.o: client-naive.c
# server-concurrent-naive.o: server-concurrent-naive.c
# client-naive: client-naive.o
# server-concurrent-naive: server-concurrent-naive.o

clean:
	@rm -rf $(TARGETS) *.zip *.o *.dSYM *~

dist:
	@zip $(ARCHIVE) $(SOURCES) client-lpd.py Makefile xmake.lua Testo\ Esercizio*
