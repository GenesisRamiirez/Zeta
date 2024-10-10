#ifndef RUTA_HPP
#define RUTA_HPP

#include "NodoRuta.hpp"

class Ruta 
{
    public:
        NodoRuta* raiz;

        Ruta();
        ~Ruta();
        void agregarRuta(NodoRuta* nuevoNodo);
};

#endif // RUTA_HPP