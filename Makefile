CC = gcc
EXESRC = src/main.c
BINDIR = bin
SRCDIR = src
INCDIR = inc
EXE = bin/game.exe

SRCS = $(wildcard $(SRCDIR)/**/*.c)
EXEOBJ = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(EXESRC))
OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCS))
CFLAGS = -I $(INCDIR)

.PHONY: all clean

all: dirs libs game

dirs:
	mkdir -p $(BINDIR)

libs:

$(BINDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

game: $(EXEOBJ) $(OBJS)
	gcc $(OBJS) $< -o $(EXE) -lm
	
clean:
	rm -rf $(BINDIR)
