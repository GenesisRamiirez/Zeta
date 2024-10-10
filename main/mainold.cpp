#include "simulador.h"
#include <iostream>
#include <limits>
double estimate_time(double fitness_level, double age, double weight, double distance, double elevation_gain) 
{
  
  double time = 0.0;
  if (fitness_level > 0.5) {
    time = distance / (fitness_level * 0.1);
  } else {
    time = distance / (age * 0.05);
  }
  time += elevation_gain * 0.01;
  return time;
}

int main() 
{
    Simulador simulador;

    std::cout << "Bienvenido al simulador de ascenso al Pico Bolivar!" << std::endl;
    std::cout << "Por favor, ingrese sus datos:" << std::endl;

    simulador.agregar_persona();

    simulador.agregar_rutas();

    std::cout << "Rutas disponibles:" << std::endl;
    for (int i = 0; i < simulador.get_rutas_size(); i++) {
        std::cout << i + 1 << ". " << simulador.get_ruta_nombre(i) << std::endl;
    }

    simulador.seleccionar_ruta();

    std::cout << "Ruta seleccionada: " << simulador.get_ruta_seleccionada() << std::endl;

    simulador.mostrar_datos_persona();
    simulador.mostrar_datos_ruta();

    // Recommend the most suitable route
    std::string nombre_persona = simulador.get_persona_nombre();
    double min_tiempo_cumbre = std::numeric_limits<double>::max();
    std::string ruta_recomendada;
    for (int i = 0; i < simulador.get_rutas_size(); i++) {
        std::string ruta_nombre = simulador.get_ruta_nombre(i);
        double tiempo_cumbre = simulador.estimar_tiempo_cumbre(nombre_persona, ruta_nombre);
        if (tiempo_cumbre < min_tiempo_cumbre) {
            min_tiempo_cumbre = tiempo_cumbre;
            ruta_recomendada = ruta_nombre;
        }
    }

    double fitness_level = 0.7; // Example value
    double age = 30.0; // Example value
    double weight = 70.0; // Example value
    double distance = 10.0; // Example value
    double elevation_gain = 500.0; // Example value

    double estimated_time = estimate_time(fitness_level, age, weight, distance, elevation_gain);
    std::cout << "Estimated time to reach the recommended route: " << estimated_time << " hours" << std::endl;

    std::cout << "Ruta recomendada: " << ruta_recomendada << " (Tiempo estimado: " << min_tiempo_cumbre << " horas)" << std::endl;

    return 0;
}
