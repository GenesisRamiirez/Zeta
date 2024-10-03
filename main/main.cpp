#include "simulador.h"
#include <iostream>
#include <limits>
double estimateTime(double fitnessLevel, double age, double weight, double distance, double elevationGain) {
  // Define a model based on existing research or empirical data
  double time = 0.0;
  if (fitnessLevel > 0.5) {
    time = distance / (fitnessLevel * 0.1);
  } else {
    time = distance / (age * 0.05);
  }
  time += elevationGain * 0.01;
  return time;
}

int main() {
    Simulador simulador;

    std::cout << "Bienvenido al simulador de ascenso al Pico Bolivar!" << std::endl;
    std::cout << "Por favor, ingrese sus datos:" << std::endl;

    simulador.agregarPersona();

    simulador.agregarRutas();

    std::cout << "Rutas disponibles:" << std::endl;
    for (int i = 0; i < simulador.getRutasSize(); i++) {
        std::cout << i + 1 << ". " << simulador.getRutaNombre(i) << std::endl;
    }

    simulador.seleccionarRuta();

    std::cout << "Ruta seleccionada: " << simulador.getRutaSeleccionada() << std::endl;

    simulador.mostrarDatosPersona();
    simulador.mostrarDatosRuta();

    // Recommend the most suitable route
    std::string nombrePersona = simulador.getPersonaNombre();
    double minTiempoCumbre = std::numeric_limits<double>::max();
    std::string rutaRecomendada;
    for (int i = 0; i < simulador.getRutasSize(); i++) {
        std::string rutaNombre = simulador.getRutaNombre(i);
        double tiempoCumbre = simulador.estimarTiempoCumbre(nombrePersona, rutaNombre);
        if (tiempoCumbre < minTiempoCumbre) {
            minTiempoCumbre = tiempoCumbre;
            rutaRecomendada = rutaNombre;
        }
    }

    double fitnessLevel = 0.7; // Example value
    double age = 30.0; // Example value
    double weight = 70.0; // Example value
    double distance = 10.0; // Example value
    double elevationGain = 500.0; // Example value

    double estimatedTime = estimateTime(fitnessLevel, age, weight, distance, elevationGain);
    std::cout << "Estimated time to reach the recommended route: " << estimatedTime << " hours" << std::endl;

    std::cout << "Ruta recomendada: " << rutaRecomendada << " (Tiempo estimado: " << minTiempoCumbre << " horas)" << std::endl;

    return 0;
}
