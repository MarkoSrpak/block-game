# Specific files
CC = gcc
EXESRC = src/main.c
BINDIR = bin
SRCDIR = src
LIBDIR = lib
EXE = bin/game.exe

# General files
SRCS = $(wildcard $(SRCDIR)/**/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCS))
EXEOBJ = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(EXESRC))

# Flags for compiler and linker
CFLAGS = -I$(LIBDIR)/glad/include -I$(LIBDIR)/glfw/include -I$(LIBDIR)/glfw/deps -I$(SRCDIR) -Wall
LDFLAGS = $(BINDIR)/glad/src/gl.o $(BINDIR)/glfw/src/libglfw3.a -lm -lgdi32

.PHONY: all clean

# Make without specifications runs all three
all: dirs libs game

# Make dirs for binaries
dirs:
	mkdir -p $(BINDIR)
	mkdir -p $(BINDIR)/gfx
	mkdir -p $(BINDIR)/window

# Make project dependencies
libs:
# Compile glad
	mkdir -p $(BINDIR)/glad/src
	$(CC) -o $(BINDIR)/glad/src/gl.o -I$(LIBDIR)/glad/include -c $(LIBDIR)/glad/src/gl.c
# Generate build files for GLFW
	cmake -S $(LIBDIR)/glfw -B $(BINDIR)/glfw -G "MinGW Makefiles"
# Compile GLFW
	make -C $(BINDIR)/glfw -s

# Make object files from source files
$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

# Make executable
game: $(OBJS) $(EXEOBJ) 
	$(CC) -o $(EXE) $^ $(LDFLAGS)

# Run executable
run:
	./$(EXE)

# Clean project binaries
clean:
	rm -rf $(BINDIR)
