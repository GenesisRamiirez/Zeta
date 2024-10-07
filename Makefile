CXX         = g++ -std=c++17
WARN        = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings -Wno-parentheses -Wfloat-equal -pedantic

# Directorios
LIB         = ./lib
INCLUDES    = $(wildcard $(LIB)/include/*.h)
SOURCES     = $(wildcard $(LIB)/src/*.c)
OBJECTS     = $(SOURCES:$(LIB)/src/%.c=$(LIB)/obj/%.o)

TESTDIR     = ./test
TEST        = $(wildcard $(TESTDIR)/*.c)
MKTEST      = $(TEST:$(TESTDIR)/%.c=$(TESTDIR)/bin%)

MAIN        = ./main
MAIN_SRC    = $(wildcard $(MAIN)/*.c)
MKMAIN      = $(MAIN_SRC:$(MAIN)/%.c=$(MAIN)/bin%)

# Flags y rutas
INCLUDEPATH = -I$(LIB)/include

FLAGS       = -g -O0 -DDEBUG $(WARN)
LIBLINK     = $(OBJECTS)

all: main test

# Librería
$(LIB)/obj/%.o : $(LIB)/src/%.c
	@$(CXX) $(FLAGS) $(INCLUDEPATH) -c $< -o $@

# Pruebas
$(TESTDIR)/bin%: $(TESTDIR)/%.c $(OBJECTS)
	@$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

test: $(TEST) $(INLCUDES) $(SOURCES) $(MKTEST)

# Programa principal
$(MAIN)/bin%: $(MAIN)/%.c $(OBJECTS)
	@$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

main: $(MKMAIN) $(INCLUDES) $(SOURCES) $(MKMAIN)

.PHONY:
clean:
	@$(RM) $(MKTEST) $(MKMAIN) 
