CXX         = g++ -std=c++17
WARN        = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings -Wno-parentheses -Wfloat-equal -pedantic

#lib
LIB         = ./lib
INCLUDES    = $(wildcard $(LIB)/include/*.hpp)
SOURCES     = $(wildcard $(LIB)/src/*.cpp)
OBJECTS     = $(SOURCES:$(LIB)/src/%.cpp=$(LIB)/obj/%.o)

#test
TESTDIR     = ./test
TEST        = $(wildcard $(TESTDIR)/*.cpp)
MKTEST      = $(TEST:$(TESTDIR)/%.cpp=$(TESTDIR)/bin/%)

#main
MAIN        = ./main
MAIN_SRC    = $(wildcard $(MAIN)/*.cpp)
MKMAIN      = $(MAIN_SRC:$(MAIN)/%.cpp=$(MAIN)/bin/%)

INCLUDEPATH = -I$(LIB)/include
FLAGS       = -g -O0 -DDEBUG $(WARN)
LIBLINK     = $(OBJECTS)


all: main test

$(LIB)/obj/%.o : $(LIB)/src/%.cpp | $(LIB)/obj
	@$(CXX) $(FLAGS) $(INCLUDEPATH) -c $< -o $@

$(TESTDIR)/bin/%: $(TESTDIR)/%.cpp $(OBJECTS)
	@$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

test: $(MKTEST)

$(MAIN)/bin/%: $(MAIN)/%.cpp $(OBJECTS)
	@$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

main: $(MKMAIN)

RM = rm -f
.PHONY: clean
clean:
	@$(RM) $(TESTDIR)/bin/* $(MAIN)/bin/* $(LIB)/obj/*

