<p align="center">
<img width="460" height="300" src="https://jesuitasaru.org/wp-content/uploads/2020/08/laberinto-6-1561965744-1030x633.jpg">
</p>

# Maze Solver

> Resumen del solucionador
- Maze Solver se basa en una grid/matriz gráfica de casillas, donde cada una esta descrita por su posición, asimismo estas tienen una equivalencia a nodos. el grid se inicia totalmente vacío es decir libre de obstáculos y con un tamaño predeterminado. El usuario establece los obstáculos, el punto de partida y la meta. El objetivo del programa es hallar un camino entre el punto de partida y la meta. Se permite el movimiento en 8 direcciones (Como las de un Rey en un tablero de ajedrez).

                                                               N.W   N   N.E
                                                                \   |   /
                                                                 \  |  /
                                                        w----Casilla/Node----E
                                                                 / | \
                                                                /   |  \
                                                             S.W    S   S.E

> Resumen del programa
- El programa se basa en el uso de la librería gráfica SFML, trabaja en base a la renderización de ventanas por lo cual al inicio se crea una grid de casillas rectangulares, todas pintadas de color celeste. Mientras el usuario puede establecer los obstáculos, el punto de inicio y destino, esto a través de acciones con el ratón y teclado, asimismo el programa lee la posición del mouse para poder pintar las casillas. Estas se van pintando de distintos colores para distinguir los cambios visualmente, internamente se basa en un cambio de atributos booleanos que señalan si una casilla esta: libre, es una obstrucción o sí es el inicio o el final. Una vez que el usuario haya terminado de armar el laberinto puede correr el solver (basado en el algoritmo de pathfinding A*). Se marcan todas las casillas visitadas con color negro, y el camino más corto encontrado por el solver se pinta de blanco.

> Video explicatorio

link:

> Indicaciones
- Para esta versión del proyecto se seguirán las siguientes indicaciones para su ejecución:
1. Como se mencionó la matriz gráfica se crea con un tamaño predefinido, a través de la posición del cursor y un botón (del teclado y mouse) se diferencia entra una acción u otra. Click Izquierdo para pintar obstáculos, click derecho para quitar obstáculos. Letra Z para poner el inicio y letra A para poner el final. C para ejecutar el algoritmo que resuelve el "laberinto". 

2. Después de esta primera fase de construcción el programa usa el algoritmo para encontrar el path. Es importante señalar que debido a que la librería SFML no soporta minimizaciones todavía, es recomendable no minimizar la ventana hasta terminar el uso del programa, asimismo cada vez que se quiera volver a armar el laberinto se use la barra espaciadora lo que hará, que el grid se limpie por completo.

## Code insights

Para desarrollar el proyecto se implementaron las clases Casilla, Grid y Ventana. Con el objetivo de modularizar el programa y facilitar el uso de la librería SFML. También, esto ayuda a tener una interacción limpia entre clases.

Asimismo, se hace uso de un struct "Node" para un desarrollo más optimo y sencillo del algoritmo A*, también gracias a sus atributos bool, ayuda a reconocer de que color se va pintar una determinada casilla. 

Debido a que el problema se basa en gran medida en la interacción con el usuario se trabaja dentro de un namespace user, esto también puede ayudar posteriormente en llevar una mejor organización en próximas mejoras del programa.

<img src="https://github.com/utec-cs1103-2019-01/proyecto-battleship-estructurascontinuas/blob/master/Battleship.jpg">

## Equipo

> Contribuyentes

| <a target="_blank">**Ian**</a> | <a target="_blank">**Mauro**</a> | <a target="_blank">**Nincol Quiroz**</a> |
