CXX         = g++ -std=c++17
WARN        = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings -Wno-parentheses -Wfloat-equal -pedantic

# Dir
LIB         = ./lib
INCLUDE     = ./include
SRC         = ./src
BIN         = ./bin
MAIN        = ./main
TESTDIR     = ./tests

# FILES
INCLUDES    = $(wildcard $(INCLUDE)/*.h)
SOURCES     = $(wildcard $(SRC)/*.c)
OBJECTS     = $(SOURCES:$(SRC)/%.c=$(LIB)/%.o)

# Test
TEST        = $(wildcard $(TESTDIR)/*.c)
MKTEST      = $(TEST:$(TESTDIR)/%.c=$(BIN)/test_%)

# Main
MAIN_SRC    = $(wildcard $(MAIN)/*.c)
MKMAIN      = $(MAIN_SRC:$(MAIN)/%.c=$(BIN)/main_%)

# Flags and paths
INCLUDEPATH = -I$(INCLUDE)
FLAGS       = -g -O0 -DDEBUG $(WARN)
LIBLINK     = $(OBJECTS)

all: main test

# library
$(LIB)/%.o : $(SRC)/%.c
$(CXX) $(FLAGS) $(INCLUDEPATH) -c $< -o $@

# test
$(BIN)/test_%: $(TESTDIR)/%.c $(OBJECTS)
$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

test: $(TEST) $(INCLUDES) $(SOURCES) $(MKTEST)

$(BIN)/main_%: $(MAIN)/%.c $(OBJECTS)
$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

main: $(MAIN_SRC) $(INCLUDES) $(SOURCES) $(MKMAIN)

.PHONY: clean
clean:
$(RM) $(MKTEST) $(MKMAIN) $(OBJECTS)