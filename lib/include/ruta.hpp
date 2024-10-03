#ifndef RUTA_H
#define RUTA_H

#include <string>
#include <vector>

struct Ruta 
{
    std::string nombre;
    double distancia; // km
    double gananciaAltitud; // m
    std::vector<std::string> condiciones; // ej., lluvia, sol, viento
};

#endif  // RUTA_H