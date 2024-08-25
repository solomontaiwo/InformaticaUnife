JAVA_SOURCES := $(wildcard *.java)
JAVA_TARGETS := $(patsubst %.java,%.class,$(JAVA_SOURCES))
C_SOURCES    := $(wildcard *.[ch])
C_TARGETS    := client-naive client-td-connreuse server-concurrent-naive server-concurrent-td-connreuse
TODAY        := $(shell date +%Y%m%d)
ARCHIVE      := rps_$(TODAY).zip

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

all: $(C_TARGETS) $(JAVA_TARGETS)

# dependencies
client-td-connreuse.o: client-td-connreuse.c utils.h rxb.h
rxb.o: rxb.c rxb.h
server-concurrent-td.o: server-concurrent-td.c utils.h rxb.h
client-td-connreuse: client-td-connreuse.o utils.o rxb.o
server-concurrent-td-connreuse: server-concurrent-td-connreuse.o utils.o rxb.o
# client-naive: client-naive.o
# server-concurrent-naive: server-iterative-naive.o

%.class: %.java
	javac $<

clean:
	@rm -rf $(C_TARGETS) $(JAVA_TARGETS) *.zip *.o *.dSYM *~

dist:
	@zip $(ARCHIVE) $(C_SOURCES) $(JAVA_SOURCES) README.txt Makefile xmake.lua Testo\ Esercizio*

