#ifndef PERSONA_H
#define PERSONA_H

#include <string>

struct Persona 
{
    std::string nombre;
    std::string apellido;
    int edad;
    double ritmo_caminata; 
    bool es_atleta;
    bool tiene_experiencia;
    bool es_sedentario;
    double peso; 
    double altura; 

};

#endif  // PERSONA_H
