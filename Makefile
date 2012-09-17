
PREFIX = /usr/local
SRC = src/every.c deps/ms/ms.c deps/commander/src/commander.c
OBJ = $(SRC:.c=.o)
CFLAGS = -std=c99 -I deps/ms -I deps/commander/src

every: $(OBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

install: every
	cp -f every $(PREFIX)/bin/every

uninstall:
	rm -f $(PREFIX)/bin/every

clean:
	rm -f every $(OBJ)

.PHONY: clean install uninstall