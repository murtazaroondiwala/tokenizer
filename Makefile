
SRCDIR =src
INCDIR=include
CC=gcc
CFLAGS=-I$(INCDIR)
ODIR=object
LIBS=-lm
_DEPS = functions.h
DEPS = $(patsubst %,$(INCDIR)/%,$(_DEPS))
_SRC = finalmain.c functions.c
OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC))
bin/main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -o  $@ -c $< $(CFLAGS)
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o
	rm bin/*.exe