# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Iinclude -Wall

# Directories
SRCDIR = src
OBJDIR = obj
LIBDIR = lib
APPDIR = app
BINDIR = bin

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)

# Object files
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Library
LIB = $(LIBDIR)/libsorter.a

# Executable
APP_SRC = $(APPDIR)/main.c
EXECUTABLE = $(BINDIR)/main

# Targets

all: $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

# Create executable
$(EXECUTABLE): $(APP_SRC) $(LIB)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $< -L$(LIBDIR) -lsorter

# Create static library
$(LIB): $(OBJS)
	@mkdir -p $(LIBDIR)
	ar rcs $@ $^

# Create object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJDIR) $(LIBDIR) $(BINDIR)

.PHONY: all clean run
