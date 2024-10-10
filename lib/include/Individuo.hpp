#ifndef INDIVIDUO_HPP // Comprueba si no está definido
#define INDIVIDUO_HPP // Define INDIVIDUO_HPP

#include <iostream>
#include <string>

class Individuo 
{
    public:
    std::string nombre;
    double ritmoCaminata;
    bool esAtleta;
    bool tieneExperiencia;
    bool esSedentario;

    
    Individuo(std::string nombre, double ritmoCaminata, bool esAtleta, bool tieneExperiencia, bool esSedentario)
        : nombre(nombre), ritmoCaminata(ritmoCaminata), esAtleta(esAtleta), tieneExperiencia(tieneExperiencia), esSedentario(esSedentario) {}

   
    void imprimirDatos() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Ritmo de Caminata: " << ritmoCaminata << " km/h" << std::endl;
        std::cout << "Es Atleta: " << (esAtleta ? "Sí" : "No") << std::endl;
        std::cout << "Tiene Experiencia: " << (tieneExperiencia ? "Sí" : "No") << std::endl;
        std::cout << "Es Sedentario: " << (esSedentario ? "Sí" : "No") << std::endl;
    }
};

#endif // INDIVIDUO_HPP
