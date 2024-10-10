#include "Ruta.hpp"

Ruta::Ruta() : raiz(nullptr) {}

Ruta::~Ruta() 
{
    delete raiz; 
}

void Ruta::agregarRuta(NodoRuta* nuevoNodo) 
{
    raiz = nuevoNodo;
}