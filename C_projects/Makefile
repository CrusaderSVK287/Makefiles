#################################### USAGE #####################################

# Do not remove any variables from this section,
# If you dont want to use them, just leave them
# empty like the LIBS variable

# CC - used compiler
# LIBS - libraries to be linked, for example -lm
# CFLAGS - flags used to compile program like -Wall

# Repository structure for this makefile to work correctly
# 1. All source files must be under SRCDIR directory
# 2. main function of the program MUST be in SRCDIR/main.c
# 3. Files with source code for testing must be in TESTDIR directory

# To compile program without test flags, specify 'test=n' during make
# To run tests without coverage, specify 'nocov=y' during make 

# You can visit this makefile repository and example project here
# https://github.com/CrusaderSVK287/Makefiles/tree/main/C_projects

################################### TARGETS ####################################

# all: compiles source code into object files and result binary, call just make
# test: compiles if necesarry, executes tests and shows test coverage
# clean: cleans repository of temporary files, object files and binaries

################################ CONFIGURATION #################################
# Compiler flags
CC = gcc
LIBS =
CFLAGS = -Wall -Werror $(LIBS)
TESTFLAGS =

# Source and build directories ending with /
# DO NOT ADD SPACE AFTER /, COULD RESULT IN UNWANTED DELETION OF FILES
SRCDIR  = src/
OBJDIR  = obj/
BINDIR  = bin/
TESTDIR = test/

# Result binary name
BINNAME = bin

################################################################################
#                                                                              #
#                  DO NOT CHANGE ANYTHING BELOW THIS LINE                      #
#                                                                              #
################################################################################

### COMPILATION ###

SRCS  = $(shell find $(SRCDIR) -name '*.c')
OBJS  = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))
TSRCS = $(shell find $(TESTDIR) -name '*.c')
TOBJS = $(patsubst $(TESTDIR)%.c, $(OBJDIR)$(TESTDIR)%.o, $(TSRCS)) \
	$(subst $(OBJDIR)main.o,,$(OBJS))

# Additional compilation and output flags
test:=y
nocov:=n
ifeq ($(test), y)
  TESTFLAGS += -MMD -MP -fprofile-arcs -ftest-coverage -lgcov --coverage
endif

BIN = $(BINDIR)$(BINNAME)
RMGCOV = rm -f *.gcov

all: -setup $(BIN)

$(BIN): $(SRCDIR)main.c $(OBJS)
	@echo ""
	$(CC) $(CFLAGS) $(OBJS) $(TESTFLAGS) -o $@
	@echo "Compilation successful"

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(TESTFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR) *.gcov


### TESTS ###
$(OBJDIR)$(TESTDIR)%.o: $(TESTDIR)%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(TESTFLAGS) -I $(SRCDIR) -c $< -o $@

test: -setup $(OBJS) $(TOBJS)
	$(CC) $(CFLAGS) $(TESTFLAGS) -I $(SRCDIR) $(TOBJS) -o $(BINDIR)$@
	@echo "----- RUNNING TESTS -----"
	@$(BINDIR)$@
ifeq ($(nocov), n)
	@echo -e "----- Showing Coverage -----\nIf you do not wish to see\
	 coverage, specify nocov=y flag during make\n"
	@gcov $(subst $(OBJDIR)main.o,,$(OBJS))
endif
	@$(RMGCOV)


### SET UP ###
-setup:
ifeq ($(test), y)
	@echo -e "!!! Compiling with test flags, to disable, specify test=n \
	during make\n"
endif
	@mkdir -p $(SRCDIR) $(OBJDIR) $(BINDIR) $(TESTDIR)
