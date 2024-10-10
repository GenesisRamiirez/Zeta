#include "HashTable.hpp"

void HashTable::agregarIndividuo(const Individuo& individuo) 
{
    table[individuo.nombre] = std::make_shared<Individuo>(individuo);
}
std::shared_ptr<Individuo> HashTable::obtenerIndividuo(const std::string& nombre) 
{
    auto it = table.find(nombre);
    if (it != table.end()) 
    {
        return it->second; 
    }
    return nullptr;
}
 /* Individuo* HashTable::obtenerIndividuo(const std::string& nombre) 
 {
    auto it = table.find(nombre);
    if (it != table.end()) 
    {
        return it->second.get(); 
    }
    return nullptr;
}
*/
