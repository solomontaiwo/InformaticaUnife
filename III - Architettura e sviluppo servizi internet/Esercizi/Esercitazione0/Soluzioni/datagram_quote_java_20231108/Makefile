# Get list of all *.java source code files, create corresponding *.class target list.
SOURCES := $(wildcard *.java)
TARGETS := $(patsubst %.java,%.class,$(SOURCES))

TODAY   := $(shell date +%Y%m%d)
ARCHIVE := datagram_quote_java_$(TODAY).zip


.PHONY: clean dist

all: ${TARGETS}

%.class: %.java
	@javac $<

clean:
	@rm -f *.class *.zip *~

dist:
	@zip $(ARCHIVE) $(SOURCES) *.txt *.rb Makefile

