# Conway's Game of life
***Game of life*** o ***Juego de la vida*** es es un automata celular diceñado por el matemático británico **Jhon Horton Conway** en 1970

## El juego
Se trata de un juego de cero jugadores, su evolucion esta determinada por el estado inicial. El tablero de juego o el mundo es una malla plana de ***cuadrados/células*** que es extiende por el infinito en todas las direcciones. Por tanto cada célula tiene 8 celulas vecinas, que son las que estan proximas a ella (incluidas las diagonales). Las células tienen dos estados: ```vivas``` o ```muertas```. El estado de las celulas evoluciona por cada turno. Para determinar el estado de una celula se toma en cuenta el estado de sus vecinas para determinar su estado en el turno siguiente.
Todas las celulas se actualizan simultaneamente en cada turno, siguiendo estas reglas:
* Una celula muerta con exactamente 3 celulas vecinas vivas estara viva para el siguiente turno.
* Una celula con 2 o 3 celulas vecinas vivas sigue viva, caso contrario para el siguiente turno muere.

---
## Librerías utilizadas
* [SFML](https://www.sfml-dev.org/)

>Libreria grafica disponible para varios lenguajes de programacion como c++, c#, go, python, rust, ruby, etc.