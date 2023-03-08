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
TESTFLAGS =

# Source and build directories ending with /
# DO NOT ADD SPACE AFTER /, COULD RESULT IN UNWANTED DELETION OF FILES
SRCDIR = src/
OBJDIR = obj/
BINDIR = bin/
TESTDIR = test/

# Result binary name
BINNAME = bin

###############################################################################
#                                                                             #
#                  DO NOT CHANGE ANYTHING BELOW THIS LINE                     #
#                                                                             #
###############################################################################

### COMPILATION ###

SRCS = $(shell find $(SRCDIR) -name '*.c')
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))
TSRCS = $(shell find $(TESTDIR) -name '*.c')
TOBJS = $(patsubst $(TESTDIR)%.c, $(OBJDIR)$(TESTDIR)%.o, $(TSRCS)) \
	$(subst $(OBJDIR)main.o,,$(OBJS))

test:=y
ifeq ($(test), y)
  TESTFLAGS += -MMD -MP -fprofile-arcs -ftest-coverage -lgcov --coverage
endif

BIN = $(BINDIR)$(BINNAME)

all: -setup $(BIN)

$(BIN): $(OBJS)
	@echo ""
	$(CC) $(CFLAGS) $(OBJS) $(TESTFLAGS) -o $@
	@echo "Compilation successful"

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(TESTFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)*.o $(BINDIR)* *.gcov


### TESTS ###
$(OBJDIR)$(TESTDIR)%.o: $(TESTDIR)%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(TESTFLAGS) -I $(SRCDIR) -c $< -o $@

test: $(OBJS) $(TOBJS)
	$(CC) $(CFLAGS) $(TESTFLAGS) -I $(SRCDIR) $(TOBJS) -o $(BINDIR)$@
	@echo "----- RUNNING TESTS -----"
	@$(BINDIR)$@
	@gcov $(TOBJS)


### SET UP ###
-setup:
ifeq ($(test), y)
	@echo "!!! Compiling with test flags, to disable, specify test=n \
	during make"
	@echo ""
endif
	@mkdir -p $(SRCDIR) $(OBJDIR) $(BINDIR)
