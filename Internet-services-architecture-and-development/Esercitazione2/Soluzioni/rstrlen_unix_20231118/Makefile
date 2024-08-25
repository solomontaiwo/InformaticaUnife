SOURCES := $(wildcard *.[ch])
TODAY   := $(shell date +%Y%m%d)
ARCHIVE := rstrlen_unix_$(TODAY).zip
TARGETS := client-naive client-td server-iterative-naive server-concurrent-td

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
client-td.o: client-td.c utils.h rxb.h
rxb.o: rxb.c rxb.h
server-concurrent-td.o: server-concurrent-td.c utils.h rxb.h
client-td: client-td.o utils.o rxb.o
server-concurrent-td: server-concurrent-td.o utils.o rxb.o
# client-naive: client-naive.o
# server-iterative-naive: server-iterative-naive.o

clean:
	@rm -rf $(TARGETS) *.zip *.o *.dSYM *~

dist:
	@zip $(ARCHIVE) $(SOURCES) Makefile xmake.lua Testo\ Esercizio*

