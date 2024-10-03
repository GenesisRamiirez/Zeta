#ifndef RUTA_H
#define RUTA_H

#include <string>
#include <vector>

struct Ruta {
    std::string nombre;
    double distancia; 
    double gananciaAltitud;
    std::vector<std::string> condiciones; 
};

#endif  // RUTA_H
