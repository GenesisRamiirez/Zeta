#include <iostream>
#include <vector>
#include "Individuo.hpp"
#include "NodoRuta.hpp"
#include "Ruta.hpp"
#include "Funciones.hpp"
#include "HashTable.hpp"

int main() 

{
    HashTable tablaHash; 

   
    Ruta rutaTeleferico;
    NodoRuta* telefericoCumbre = new NodoRuta("Pico Bolívar desde Teleférico", 8.0, 3338);
    rutaTeleferico.agregarRuta(telefericoCumbre);

    Ruta rutaParqueNacional;
    NodoRuta* parqueCumbre = new NodoRuta("Pico Bolívar desde Parque Nacional", 12.0, 2578);
    rutaParqueNacional.agregarRuta(parqueCumbre);

    Ruta rutaLagunaLosLosenes;
    NodoRuta* lagunaCumbre = new NodoRuta("Pico Bolívar desde Laguna de Los Losenes", 10.0, 1578);
    rutaLagunaLosLosenes.agregarRuta(lagunaCumbre);

    
    char tipoExcursion;
    std::cout << "¿Es una sola persona o un grupo de excursionistas? (p/g): ";
    std::cin >> tipoExcursion;

    if (tipoExcursion == 'p') 
    {
        // Caso de una sola persona
        Individuo individuo = solicitarDatosIndividuo();
        tablaHash.agregarIndividuo(individuo); 

        std::cout << "Seleccione la ruta:\n";
        std::cout << "1. Teleférico (Distancia: 8.0 km, Desnivel: 3338 m)\n";
        std::cout << "2. Parque Nacional (Distancia: 12.0 km, Desnivel: 2578 m)\n";
        std::cout << "3. Laguna de Los Losenes (Distancia: 10.0 km, Desnivel: 1578 m)\n";
        int rutaSeleccionada;
        std::cin >> rutaSeleccionada;

        double tiempoEstimado;
        switch (rutaSeleccionada) 
        {
            case 1:
                tiempoEstimado = calcularTiempoEstimado(individuo, rutaTeleferico.raiz);
                break;
            case 2:
                tiempoEstimado = calcularTiempoEstimado(individuo, rutaParqueNacional.raiz);
                break;
            case 3:
                tiempoEstimado = calcularTiempoEstimado(individuo, rutaLagunaLosLosenes.raiz);
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                return 1;
        }
        std::cout << "Tiempo estimado para " << individuo.nombre << ": " << tiempoEstimado << " horas" << std::endl;
    } else if (tipoExcursion == 'g') 
    {
        // Caso de un grupo de excursionistas
        int numPersonas;
        std::cout << "Ingrese el número de personas en el grupo: ";
        std::cin >> numPersonas;

        std::vector<Individuo> grupo;
        for (int i = 0; i < numPersonas; ++i) 
        {
            std::cout << "Datos para la persona " << i + 1 << ":" << std::endl;
            Individuo individuo = solicitarDatosIndividuo();
            grupo.push_back(individuo);
            tablaHash.agregarIndividuo(individuo); 
        }

        std::cout << "Seleccione la ruta:\n";
        std::cout << "1. Teleférico (Distancia: 8.0 km, Desnivel: 3338 m)\n";
        std::cout << "2. Parque Nacional (Distancia: 12.0 km, Desnivel: 2578 m)\n";
        std::cout << "3. Laguna de Los Losenes (Distancia: 10.0 km, Desnivel: 1578 m)\n";
        int rutaSeleccionada;
        std::cin >> rutaSeleccionada;

        double tiempoMaximo = 0.0;
        for (auto& individuo : grupo) 
        {
            double tiempoEstimado;
            switch (rutaSeleccionada) 
            {
                case 1:
                    tiempoEstimado = calcularTiempoEstimado(individuo, rutaTeleferico.raiz);
                    break;
                case 2:
                    tiempoEstimado = calcularTiempoEstimado(individuo, rutaParqueNacional.raiz);
                    break;
                case 3:
                    tiempoEstimado = calcularTiempoEstimado(individuo, rutaLagunaLosLosenes.raiz);
                    break;
                default:
                    std::cout << "Opción no válida." << std::endl;
                    return 1;
            }
            std::cout << "Tiempo estimado para " << individuo.nombre << ": " << tiempoEstimado << " horas" << std::endl;
            if (tiempoEstimado > tiempoMaximo) 
            {
                tiempoMaximo = tiempoEstimado;
            }
        }

        std::cout << "Tiempo estimado para el grupo: " << tiempoMaximo << " horas" << std::endl;
    } else 
    {
        std::cout << "Opción no válida." << std::endl;
    }
std::string nombreBuscar;
std::cout << "Ingrese el nombre para buscar en la tabla hash: ";
std::cin.ignore();
std::getline(std::cin, nombreBuscar);

//Individuo* encontrado = tablaHash.obtenerIndividuo(nombreBuscar);
std::shared_ptr<Individuo> encontrado = tablaHash.obtenerIndividuo(nombreBuscar);

if (encontrado != nullptr) 
{
    std::cout << "Individuo encontrado: " << std::endl;
    encontrado->imprimirDatos();
} else 
{
    std::cout << "Individuo no encontrado." << std::endl;
}

  // Limpiar memoria
    //delete telefericoCumbre;
    //delete parqueCumbre;
    //delete lagunaCumbre;

    return 0;
}
