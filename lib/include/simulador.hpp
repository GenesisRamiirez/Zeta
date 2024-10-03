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
    int get_rutas_size();
    std::string get_ruta_nombre(int index);
    std::string get_persona_nombre();
    void agregar_persona();
    void agregar_rutas();
    void seleccionar_ruta();
    std::string get_ruta_seleccionada();
    void mostrar_datos_persona();
    void mostrar_datos_ruta();
    double estimar_tiempo_cumbre(std::string nombre_persona, std::string nombre_ruta);

private:
    std::unordered_map<std::string, Persona> individuos_;
    std::vector<Ruta> rutas_;
    std::string ruta_seleccionada_;
};

#endif  // SIMULADOR_H