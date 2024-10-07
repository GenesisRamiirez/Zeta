CXX         = g++ -std=c++17
WARN        = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings -Wno-parentheses -Wfloat-equal -pedantic

# Directorios
LIB         = ./lib
INCLUDE     = ./include
SRC         = ./src
BIN         = ./bin
MAIN        = ./main
TESTDIR     = ./tests

# Archivos
INCLUDES    = $(wildcard $(INCLUDE)/*.h)
SOURCES     = $(wildcard $(SRC)/*.c)  # Ajustado aquí
OBJECTS     = $(SOURCES:$(SRC)/%.c=$(LIB)/%.o)

# Pruebas
TEST        = $(wildcard $(TESTDIR)/*.c)
MKTEST      = $(TEST:$(TESTDIR)/%.c=$(BIN)/test_%)

# Main
MAIN_SRC    = $(wildcard $(MAIN)/*.c)
MKMAIN      = $(MAIN_SRC:$(MAIN)/%.c=$(BIN)/main_%)

# Flags y rutas
INCLUDEPATH = -I$(INCLUDE)
FLAGS       = -g -O0 -DDEBUG $(WARN)
LIBLINK     = $(OBJECTS)

all: main test

# Librería
$(LIB)/%.o : $(SRC)/%.c
	@$(CXX) $(FLAGS) $(INCLUDEPATH) -c $< -o $@

# Pruebas
$(BIN)/test_%: $(TESTDIR)/%.c $(OBJECTS)
	@$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

test: $(MKTEST)

# Programa principal
$(BIN)/main_%: $(MAIN)/%.c $(OBJECTS)
	@$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

main: $(MKMAIN)

# Regla de limpieza
RM          = rm -f
.PHONY: clean
clean:
	@$(RM) $(MKTEST) $(MKMAIN) $(OBJECTS)
