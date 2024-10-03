# Zeta
# Sistema de Ascenso Al Pico Bolívar

## Descripción del Proyecto
Este proyecto tiene como objetivo desarrollar un simulador que calcule el tiempo que un grupo de individuos tarda en coronar el Pico Bolívar desde su base. No se trata simplemente de calcular el tiempo de recorrido entre un punto A y un punto B, ya que hay múltiples variables a considerar que pueden modificar este cálculo.

## Datos Recogidos del Usuario
El programa debe recibir datos de cada individuo, incluyendo:

### Variables de Condiciones Físicas
- Ritmo de caminata de cada individuo (ejemplo: Carlos recorre 10 km en 60 minutos a nivel del mar aproximadamente a 1360 m.s.n.m).
- Estado físico (atleta o no).
- Experiencia en montañismo (tiene experiencia o no).
- Nivel de sedentarismo.

Estos datos se almacenan en tablas hash, permitiendo registrar información asociada a identificadores únicos de cada individuo. Esta estructura permite un acceso rápido a los datos (O(1)) y es escalable, facilitando la gestión de un mayor número de individuos.

## Variables Meteorológicas
Además de las condiciones físicas, se deben considerar variables meteorológicas que dependen de la época del año, tales como:
- Lluvia
- Humedad
- Sol
- Tormentas
- Viento

## Simulación del Recorrido
La simulación del recorrido considera las rutas alternativas establecidas por guías de montaña, donde se incluye información crucial que influye en el cálculo del tiempo de cumbre, tales como:
- Ruta escogida.
- Campamentos que son puntos de descanso en el recorrido.
- Tipo de terreno.
- Desnivel positivo acumulado.

La estructura de datos utilizada para representar las redes de caminos es un árbol, con las siguientes características:
- Los nodos representan las rutas.
- Los hijos representan puntos en el camino (como campamentos, bifurcaciones y condiciones).
- Las ramas representan las conexiones entre ellos.

Este enfoque es adecuado para calcular la ruta óptima y el tiempo de recorrido, teniendo en cuenta las distintas variables (condiciones físicas de los individuos, tipo de terreno, etc.). Con todos estos datos, se pueden estimar diferentes tiempos de cumbre, ya que cada elección y condición puede alterar el resultado final.

> Para ver la representación gráfica, consulta el siguiente [enlace](https://drive.google.com/drive/folders/1GSaResycQnDB9HU1JR-T7NniCmSxDMLk?usp=sharing).

## Integración de Qt y OpenGL para la GUI
Se utilizarán Qt y OpenGL juntos para crear una interfaz gráfica rica y detallada. Qt proporcionará una interfaz interactiva, ideal para paneles de control y visualización de datos en 2D, mientras que OpenGL se encargará de renderizar el terreno y las rutas en 3D. La integración de Qt con OpenGL se realizará mediante el widget `QOpenGLWidget`, permitiendo combinar la funcionalidad de Qt con la potencia gráfica de OpenGL, logrando una simulación interactiva.

**Nota**: El uso de 3D aún no está completamente decidido y se confirmará a medida que evolucione el proyecto.

## Conclusiones
Este simulador no solo calcula el tiempo de recorrido entre dos puntos, sino que también tiene en cuenta una variedad de factores que impactan el rendimiento de cada individuo en la montaña. Los avances realizados hasta ahora representan un paso significativo hacia un modelo completo y funcional.

## Próximos Pasos
- Continuar la implementación de la interfaz de usuario.
- Realizar pruebas de simulación con diferentes escenarios.
- Ajustar los algoritmos de estimación según los resultados obtenidos.
