Clase para detectar flancos de subida o bajada

Autor: Robert Sallent 
Curso: programación de placas robóticas en CIFO Sabadell 
Versión: 1.0.0
 

CREACIÓN DEL OBJETO FLANCO
--------------------------
Primero, crearemos un objeto Flanco para cada elemento que queramos analizar.
Por ejemplo, si tenemos un pulsador queremos vigilar a lo largo
de todo el programa, haremos una variable global así:

Flanco flanco();


INICIALIZACIÓN
--------------------------
El siguiente paso es vincular el objeto flanco con el pin donde se encuentra el 
pulsador, para ello usaremos el método inicializar() desde el método setup()
de la siguiente forma:

flanco.inicializar(12);  // suponiendo que el pin es el 12


USO DEL MÉTODO detectar()
--------------------------
Desde el método loop(), podemos detectar si se ha producido algún flanco haciendo:

flanco.detectar()

Este método retorna -1 para un fanco de bajada, 0 si no hay flanco y 1 para un flanco de subida.

Se han definido también tres constantes para cada uno de esos valores:
Flanco::BAJADA
Flanco::NO
FLANCO::SUBIDA

Ejemplo de uso para detectar un flanco de bajada: 
 
if(flanco.detectar() == Flanco::BAJADA)
     Serial.print("Detectado flanco de bajada.");

Si queremos detectar un flanco, independientemente que sea de subida o de bajada, podemos hacer:

if(flanco.detectar())
     Serial.print("Detectado flanco");


USO DE LOS MÉTODOS subida() Y bajada()
--------------------------------------

Existen dos métodos adicionales para simplificar la comparación.
Los métodos subida() y bajada() retornan true o false en función de si se ha producido
el flanco de subida/bajada.

Ejemplo de uso para detectar flanco de subida:

if(flanco.subida())
     Serial.print("Detectado flanco de subida.");


Ejemplo de uso para detectar flanco de bajada:

if(flanco.bajada())
     Serial.print("Detectado flanco de bajada.");

 
CONSIDERACIONES IMPORTANTES
--------------------------------------

Si usamos varios de los métodos anteriores, o varias veces el mismo, para
un mismo pin en un mismo ciclo, la detección no será correcta tras la primera vez.

El uso recomendado de esta librería es el de crear una variable de tipo entero
para guardar el valor que retorne el método detectar(). A partir de ese punto podremos
consultar el valor de la variable en cualquier parte.

Por ejemplo:

int deteccion = flanco.detectar();


if(deteccion == Flanco::BAJADA) ...




