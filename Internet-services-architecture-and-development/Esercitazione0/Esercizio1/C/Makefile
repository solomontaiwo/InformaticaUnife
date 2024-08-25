# Get list of all *.java source code files, create corresponding *.class target list.
JAVA_SOURCES := $(wildcard *.java)
JAVA_TARGETS := $(patsubst %.java,%.class,$(JAVA_SOURCES))
C_SOURCES    := $(wildcard *.[ch])
C_TARGETS    := client server
TODAY   := $(shell date +%Y%m%d)
ARCHIVE := remote_head_$(TODAY).zip

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

client: client.o utils.o
server: server.o rxb.o

%.class: %.java
	javac $<

clean:
	@rm -rf $(C_TARGETS) $(JAVA_TARGETS) infer-out *.zip *.o *.dSYM *~

dist:
	@zip $(ARCHIVE) $(C_SOURCES) $(JAVA_SOURCES) *.rb *.txt Makefile

