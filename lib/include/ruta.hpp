#ifndef RUTA_H
#define RUTA_H

#include <string>
#include <vector>

struct Ruta 
{
    std::string nombre;
    double distancia; 
    double ganancia_altitud;
    std::vector<std::string> condiciones; 
};

#endif  // RUTA_H
