#include "persona.h"
#include "ruta.h"
#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <unordered_map>
#include <vector>
#include <string>

class Simulador 
{
public:
    int getRutasSize();
    std::string getRutaNombre(int index);
    std::string getPersonaNombre();
    void agregarPersona();
    void agregarRutas();
    void seleccionarRuta();
    std::string getRutaSeleccionada();
    void mostrarDatosPersona();
    void mostrarDatosRuta();
    double estimarTiempoCumbre(std::string nombrePersona, std::string nombreRuta);

private:
    std::unordered_map<std::string, Persona> individuos_;
    std::vector<Ruta> rutas_;
    std::string rutaSeleccionada_;
};

#endif  // SIMULADOR_H