CXX         = g++ -std=c++17
WARN        = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings -Wno-parentheses -Wfloat-equal -pedantic

# Directorios
LIB         = ./lib
INCLUDES    = $(wildcard $(LIB)/include/*.h)
SOURCES     = $(wildcard $(LIB)/src/*.c)
OBJECTS     = $(SOURCES:$(LIB)/src/%.c=$(LIB)/obj/%.o)

TESTDIR     = ./test
TEST        = $(wildcard $(TESTDIR)/*.c)
MKTEST      = $(TEST:$(TESTDIR)/%.c=$(TESTDIR)/bin/%)

MAIN        = ./main
MAIN_SRC    = $(wildcard $(MAIN)/*.c)
MKMAIN      = $(MAIN_SRC:$(MAIN)/%.c=$(MAIN)/bin/%)

# Flags y rutas
INCLUDEPATH = -I$(LIB)/include
FLAGS       = -g -O0 -DDEBUG $(WARN)
LIBLINK     = $(OBJECTS)

# Regla por defecto
all: main test

# Crear el directorio de objetos si no existe
$(LIB)/obj:
	mkdir -p $(LIB)/obj

# Librería
$(LIB)/obj/%.o : $(LIB)/src/%.c | $(LIB)/obj
	@$(CXX) $(FLAGS) $(INCLUDEPATH) -c $< -o $@

# Pruebas
$(TESTDIR)/bin/%: $(TESTDIR)/%.c $(OBJECTS)
	@$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

test: $(MKTEST)

# Programa principal
$(MAIN)/bin/%: $(MAIN)/%.c $(OBJECTS)
	@$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

main: $(MKMAIN)

# Regla de limpieza
RM = rm -f
.PHONY: clean
clean:
	@$(RM) $(TESTDIR)/bin/* $(MAIN)/bin/* $(LIB)/obj/*

