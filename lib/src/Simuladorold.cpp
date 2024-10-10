#include "simulador.hpp"
#include "persona.hpp"
#include "ruta.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>
#include <cmath>

int Simulador::get_rutas_size() 
{
    return rutas_.size();
}

std::string Simulador::get_ruta_nombre(int index) 
{
    return rutas_[index].nombre;
}

std::string Simulador::get_persona_nombre() 
{
    return individuos_.begin()->first;
}

void Simulador::agregar_persona() 
{
    Persona persona;
    std::cout << "Ingrese su nombre: ";
    std::cin >> persona.nombre;
    std::cout << "Ingrese su apellido: ";
    std::cin >> persona.apellido;
    std::cout << "Ingrese su edad: ";
    std::cin >> persona.edad;
    std::cout << "Ingrese su ritmo de caminata (km/h): ";
    std::cin >> persona.ritmoCaminata;
    std::cout << "¿Es atleta? (s/n): ";
    char atleta;
    std::cin >> atleta;
    persona.es_atleta = (atleta == 's');
    std::cout << "¿Tiene experiencia? (s/n): ";
    char experiencia;
    std::cin >> experiencia;
    persona.tiene_experiencia = (experiencia == 's');
    std::cout << "¿Es sedentario? (s/n): ";
    char sedentario;
    std::cin >> sedentario;
    persona.es_sedentario = (sedentario == 's');
    std::cout << "Ingrese su peso (kg): ";
    std::cin >> persona.peso;
    std::cout << "Ingrese su altura (m): ";
    std::cin >> persona.altura;
   

    individuos_[persona.nombre] = persona;
}

void Simulador::agregar_rutas() 
{
    rutas_.push_back(Ruta{"Ruta estándar o tradicional", 13.5, 2500, {"lluvia", "sol"}});
    rutas_.push_back(Ruta{"Ruta del Glaciar", 13.5, 2500, {"hielo", "viento"}});
    rutas_.push_back(Ruta{"Ruta Norte", 15.0, 2800, {"lluvia", "nieve"}});
}

void Simulador::seleccionar_ruta() 
{
    std::cout << "Seleccione una ruta:" << std::endl;
    for (int i = 0; i < rutas_.size(); i++) {
        std::cout << i + 1 << ". " << rutas_[i].nombre << std::endl;
    }
    int opcion;
    std::cout << "Ingrese el número de la ruta: ";
    std::cin >> opcion;
    ruta_seleccionada_ = rutas_[opcion - 1].nombre;
}

std::string Simulador::get_ruta_seleccionada() 
{
    return ruta_seleccionada_;
}

void Simulador::mostrar_datos_persona() 
{
    std::cout << "Datos de la persona:" << std::endl;
    for (auto& persona : individuos_) 
    {
        std::cout << "Nombre: " << persona.second.nombre << std::endl;
        std::cout << "Apellido: " << persona.second.apellido << std::endl;
        std::cout << "Edad: " << persona.second.edad << std::endl;
        std::cout << "Ritmo de caminata: " << persona.second.ritmo_caminata << " km/h" << std::endl;
        std::cout << "Es atleta: " << (persona.second.esAtleta ? "Sí" : "No") << std::endl;
        std::cout << "Tiene experiencia: " << (persona.second.tiene_experiencia ? "Sí" : "No") << std::endl;
        std::cout << "Es sedentario: " << (persona.second.es_sedentario ? "Sí" : "No") << std::endl;
        std::cout << "Peso: " << persona.second.peso << " kg" << std::endl;
        std::cout << "Altura: " << persona.second.altura << " m" << std::endl;
    }
}

void Simulador::mostrar_datos_ruta() 
{
    std::cout << "Datos de la ruta seleccionada:" << std::endl;
    for (auto& ruta : rutas_) 
    {
        if (ruta.nombre == ruta_seleccionada_) 
        {
            std::cout << "Nombre: " << ruta.nombre << std::endl;
            std::cout << "Distancia: " << ruta.distancia << " km" << std::endl;
            std::cout << "Ganancia de altitud: " << ruta.ganancia_altitud << " m" << std::endl;
            std::cout << "Condiciones: ";
            for (auto& condicion : ruta.condiciones) 
            {
                std::cout << condicion << " ";
            }
            std::cout << std::endl;
        }
    }
}

double Simulador::estimar_tiempo_cumbre(std::string nombre_persona, std::string nombre_ruta) 
{
 
    Persona persona = individuos_[nombre_persona];


    Ruta ruta;
    for (auto& r : rutas_) 
    {
        if (r.nombre == nombre_ruta) 
        {
            ruta = r;
            break;
        }
    }

   
    double tiempo_cumbre = 0.0;
    if (persona.es_atleta) 
    {
        tiempo_cumbre = ruta.distancia / (persona.ritmo_caminata * 0.8); 
    } else if (persona.tiene_experiencia) 
    {
        tiempo_cumbre = ruta.distancia / (persona.ritmo_caminata * 0.6); 
    } else 
    {
        tiempoCumbre = ruta.distancia / (persona.ritmo_caminata * 0.4); 
    }

   
    tiempo_cumbre += ruta.ganancia_altitud / 100;
    for (auto& condicion : ruta.condiciones) 
    {
        if (condicion == "lluvia" || condicion == "nieve") 
        {
            tiempo_cumbre += 0.5; 
        }
    }

    return tiempo_cumbre;
}
