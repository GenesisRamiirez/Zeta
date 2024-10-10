#ifndef NODORUTA_HPP
#define NODORUTA_HPP

#include <string>

class NodoRuta 
{
    public:
        std::string nombre;
        double distancia; 
        double desnivel;  

        NodoRuta(std::string nombre, double distancia, double desnivel);
};

#endif // NODORUTA_HPP