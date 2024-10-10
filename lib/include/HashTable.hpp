#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <unordered_map>
#include <memory>
#include <string>
#include "Individuo.hpp"

class HashTable 
{
    public:
    std::unordered_map<std::string, std::shared_ptr<Individuo>> table;

    void agregarIndividuo(const Individuo& individuo);
    std::shared_ptr<Individuo> obtenerIndividuo(const std::string& nombre);
};

#endif // HASHTABLE_HPP
/* #ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <unordered_map>
#include <memory>
#include <string>
#include "Individuo.hpp"

class HashTable {
public:
    std::unordered_map<std::string, std::shared_ptr<Individuo>> table;

    void agregarIndividuo(const Individuo& individuo);
    Individuo* obtenerIndividuo(const std::string& nombre);
};

#endif // HASHTABLE_HPP */