CC	:= cc
CFLAGS	:= -std=c99 -pedantic -Wall

PREFIX	:= /usr/local
MANPAGE	:= $(PREFIX)/share/man
DIR	:= $(PREFIX)/bin

TARGETS	:= freq
OBJ	:= freq.o
MAN	:= freq.1

.PHONY: all clean

all: freq

clean:
	rm -rf $(TARGETS) $(OBJ)
.c.o:
	$(CC) -c $(CFLAGS) $<

freq: $(OBJ)
	$(CC) -o $@ $(OBJ)

install: all
	install $(TARGETS) $(DIR)/$(TARGETS)
	install $(MAN) $(MANPAGE)/man1/$(MAN)

