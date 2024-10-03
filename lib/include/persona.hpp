#ifndef PERSONA_H
#define PERSONA_H

#include <string>

struct Persona {
    std::string nombre;
    std::string apellido;
    int edad;
    double ritmoCaminata; // km/h
    bool esAtleta;
    bool tieneExperiencia;
    bool esSedentario;
    double peso; // kg
    double altura; // m
    // Agregue más variables de condición física según sea necesario
};

#endif  // PERSONA_H