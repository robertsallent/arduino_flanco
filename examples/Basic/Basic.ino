/*  EJEMPLO: uso de la librería para detectar flancos
 *  
 *  Autor: Robert Sallent 
 *  Curso: programación de placas robóticas en CIFO Sabadell 
 *  Versión: 1.0.0
 *
 *  En este ejemplo encenderemos o apagaremos un led conectado al pin 2 cuando 
 *  se produzca un flanco de bajada en el botón conectado al pin 12.
 *
 *  La recomendación es guardar el resultado de la detección en una variable,
 *  que luego podremos usar en cualquier parte del sketch.
 */

#include <Flanco.h>

const int BOTON = 12;
const int LED   = 2;

// PRIMERO creamos un objeto de tipo flanco.
Flanco flanco; 


// inicialización
void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  pinMode(BOTON, INPUT_PULLUP);

  // SEGUNDO vinculamos el objeto al pin con el que queremos trabajar.
  flanco.inicializar(BOTON);
}

void loop() {
  static bool encendido = false; // variable que controla el led

  // Ahora ya podemos DETECTAR FLANCOS usando el método detectar().
  // Obtendremos uno de los siguientes valores: Flanco::BAJADA, Flanco::NO o Flanco::SUBIDA  
  // que tienen los valores -1, 0 y 1 respectivamente.
  int deteccion = flanco.detectar();


  if(deteccion == Flanco::BAJADA)  
    encendido = !encendido; 

  digitalWrite(LED, encendido);

  /*
  * Para detectar flanco de subida haríamos:
  * if(deteccion == Flanco::SUBIDA)  
  *   
  * Y si queremos detectar un flanco, da igual de subida que de bajada:
  * if(deteccion)
  *
  */
    
}
