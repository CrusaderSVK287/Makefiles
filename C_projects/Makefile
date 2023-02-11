# Do not remove any variables from this section,
# If you dont want to use them, just leave them
# empty like the LIBS variable

# CC - used compiler
# LIBS - libraries to be linked, for example -lm
# CFLAGS - flags used to compile program like -Wall

# Compiler flags
CC = gcc
LIBS =
CFLAGS = -Wall -Werror $(LIBS)

# Source and build directories
SRCDIR = src/
OBJDIR = obj/
BINDIR = bin/

# Result binary name
BINNAME = test

###############################################################################
#                                                                             #
#                  DO NOT CHANGE ANYTHING BELOW THIS LINE                     #
#                                                                             #
###############################################################################

### COMPILATION ###

SRCS = $(shell find $(SRCDIR) -name '*.c')
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

BIN = $(BINDIR)$(BINNAME)
RUN = $(BIN) $(RUNARGS)

all: -setup $(BIN)

$(BIN): $(OBJS)
	@echo ""
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "Compilation successful"

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)* $(BINDIR)*

### SET UP ###
-setup:
	@mkdir -p $(SRCDIR) $(OBJDIR) $(BINDIR)
