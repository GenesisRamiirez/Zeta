#include "Funciones.hpp"
#include <iostream>

double calcularTiempoEstimado(Individuo& individuo, NodoRuta* rutaActual) 
{
    double tiempoTotal = 0.0;
    if (!rutaActual) return tiempoTotal;

    double velocidad = individuo.ritmoCaminata;
    if (individuo.esSedentario) velocidad *= 0.8;
    if (individuo.esAtleta) velocidad *= 1.2;
    if (!individuo.tieneExperiencia) velocidad *= 0.9;

    tiempoTotal += rutaActual->distancia / velocidad;

    // Ajusta el tiempo por el desnivel
    tiempoTotal += rutaActual->desnivel / 100.0; 

    return tiempoTotal;
}

Individuo solicitarDatosIndividuo() 
{
    std::string nombre;
    double ritmoCaminata;
    char esAtletaChar, tieneExperienciaChar, esSedentarioChar;

    std::cout << "Ingrese el nombre del individuo: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    
    std::cout << "Ingrese el ritmo de caminata (km/h) del individuo: ";
    std::cin >> ritmoCaminata;
    
    std::cout << "¿Es atleta? (s/n): ";
    std::cin >> esAtletaChar;
    
    std::cout << "¿Tiene experiencia? (s/n): ";
    std::cin >> tieneExperienciaChar;
    
    std::cout << "¿Es sedentario? (s/n): ";
    std::cin >> esSedentarioChar;

    bool esAtleta = (esAtletaChar == 's');
    bool tieneExperiencia = (tieneExperienciaChar == 's');
    bool esSedentario = (esSedentarioChar == 's');

    return Individuo(nombre, ritmoCaminata, esAtleta, tieneExperiencia, esSedentario);
}