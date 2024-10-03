#include "simulador.hpp"
#include "persona.hpp"
#include "ruta.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>
#include <cmath>

int Simulador::getRutasSize() 
{
    return rutas_.size();
}

std::string Simulador::getRutaNombre(int index) 
{
    return rutas_[index].nombre;
}

std::string Simulador::getPersonaNombre() 
{
    return individuos_.begin()->first;
}

void Simulador::agregarPersona() 
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
    persona.esAtleta = (atleta == 's');
    std::cout << "¿Tiene experiencia? (s/n): ";
    char experiencia;
    std::cin >> experiencia;
    persona.tieneExperiencia = (experiencia == 's');
    std::cout << "¿Es sedentario? (s/n): ";
    char sedentario;
    std::cin >> sedentario;
    persona.esSedentario = (sedentario == 's');
    std::cout << "Ingrese su peso (kg): ";
    std::cin >> persona.peso;
    std::cout << "Ingrese su altura (m): ";
    std::cin >> persona.altura;
   

    individuos_[persona.nombre] = persona;
}

void Simulador::agregarRutas() 
{
    rutas_.push_back(Ruta{"Ruta estándar o tradicional", 13.5, 2500, {"lluvia", "sol"}});
    rutas_.push_back(Ruta{"Ruta del Glaciar", 13.5, 2500, {"hielo", "viento"}});
    rutas_.push_back(Ruta{"Ruta Norte", 15.0, 2800, {"lluvia", "nieve"}});
}

void Simulador::seleccionarRuta() 
{
    std::cout << "Seleccione una ruta:" << std::endl;
    for (int i = 0; i < rutas_.size(); i++) {
        std::cout << i + 1 << ". " << rutas_[i].nombre << std::endl;
    }
    int opcion;
    std::cout << "Ingrese el número de la ruta: ";
    std::cin >> opcion;
    rutaSeleccionada_ = rutas_[opcion - 1].nombre;
}

std::string Simulador::getRutaSeleccionada() 
{
    return rutaSeleccionada_;
}

void Simulador::mostrarDatosPersona() 
{
    std::cout << "Datos de la persona:" << std::endl;
    for (auto& persona : individuos_) 
    {
        std::cout << "Nombre: " << persona.second.nombre << std::endl;
        std::cout << "Apellido: " << persona.second.apellido << std::endl;
        std::cout << "Edad: " << persona.second.edad << std::endl;
        std::cout << "Ritmo de caminata: " << persona.second.ritmoCaminata << " km/h" << std::endl;
        std::cout << "Es atleta: " << (persona.second.esAtleta ? "Sí" : "No") << std::endl;
        std::cout << "Tiene experiencia: " << (persona.second.tieneExperiencia ? "Sí" : "No") << std::endl;
        std::cout << "Es sedentario: " << (persona.second.esSedentario ? "Sí" : "No") << std::endl;
        std::cout << "Peso: " << persona.second.peso << " kg" << std::endl;
        std::cout << "Altura: " << persona.second.altura << " m" << std::endl;
    }
}

void Simulador::mostrarDatosRuta() 
{
    std::cout << "Datos de la ruta seleccionada:" << std::endl;
    for (auto& ruta : rutas_) 
    {
        if (ruta.nombre == rutaSeleccionada_) 
        {
            std::cout << "Nombre: " << ruta.nombre << std::endl;
            std::cout << "Distancia: " << ruta.distancia << " km" << std::endl;
            std::cout << "Ganancia de altitud: " << ruta.gananciaAltitud << " m" << std::endl;
            std::cout << "Condiciones: ";
            for (auto& condicion : ruta.condiciones) 
            {
                std::cout << condicion << " ";
            }
            std::cout << std::endl;
        }
    }
}

double Simulador::estimarTiempoCumbre(std::string nombrePersona, std::string nombreRuta) 
{
 
    Persona persona = individuos_[nombrePersona];


    Ruta ruta;
    for (auto& r : rutas_) 
    {
        if (r.nombre == nombreRuta) 
        {
            ruta = r;
            break;
        }
    }

   
    double tiempoCumbre = 0.0;
    if (persona.esAtleta) 
    {
        tiempoCumbre = ruta.distancia / (persona.ritmoCaminata * 0.8); 
    } else if (persona.tieneExperiencia) 
    {
        tiempoCumbre = ruta.distancia / (persona.ritmoCaminata * 0.6); 
    } else 
    {
        tiempoCumbre = ruta.distancia / (persona.ritmoCaminata * 0.4); 
    }

   
    tiempoCumbre += ruta.gananciaAltitud / 100;
    for (auto& condicion : ruta.condiciones) 
    {
        if (condicion == "lluvia" || condicion == "nieve") 
        {
            tiempoCumbre += 0.5; 
        }
    }

    return tiempoCumbre;
}
