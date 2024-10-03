# Zeta
# Sistema de Ascenso Al Pico Bolivar

## Descripción
Este proyecto tiene como objetivo simular el recorrido de montañismo, teniendo en cuenta diversas variables que pueden influir en el tiempo de llegada a la cumbre. A través de la recopilación de datos del usuario y condiciones meteorológicas, buscamos estimar tiempos más precisos basados en el perfil individual y las condiciones del entorno.

## Avances Realizados

### Datos Recogidos del Usuario
El programa requiere ingresar los siguientes datos para cada individuo:

- **Datos Básicos**
  - Nombre
  - Apellido
  - Edad
  - Altura
  - Peso

- **Condiciones Físicas**
  - Ritmo de caminata (ejemplo: Carlos recorre 10 km en 60 minutos a nivel del mar aproximadamente a 1360 m.s.n.m).
  - Estado físico (atleta o no).
  - Experiencia en montañismo (tiene experiencia o no).
  - Nivel de sedentarismo.

### Variables Meteorológicas
Se han considerado varios factores meteorológicos que pueden influir en la simulación, incluyendo:

- Lluvia
- Humedad
- Sol
- Tormentas
- Viento

### Simulación del Recorrido
Se ha desarrollado un modelo que simula el recorrido de montañismo, teniendo en cuenta:

- Rutas alternativas establecidas por guías de montaña.
- Información sobre campamentos (puntos de descanso).
- Tipo de terreno.
- Desnivel positivo acumulado.

Este modelo de simulación permite obtener estimaciones más precisas sobre el tiempo de cumbre.

### Estimación de Tiempos de Cumbre
Con todos los datos recopilados y modelados, el simulador es capaz de estimar diferentes tiempos de cumbre. Esto se realiza considerando cómo cada elección y condición puede afectar el resultado final.

## Próximos Pasos
- Continuar la implementación de la interfaz de usuario mediante la integración de **Mapbox**.
- Realizar pruebas de simulación con diferentes escenarios.
- Ajustar los algoritmos de estimación basados en los resultados obtenidos.
