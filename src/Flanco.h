/*  Detector de flancos
 *
 *  -- Fichero de cabecera - 
 *  
 *  Autor: Robert Sallent 
 *  Curso: programación de placas robóticas en CIFO Sabadell 
 *  Versión: 1.0.0
 *  
 */

#ifndef FLANCOS_CIFO
#define FLANCOS_CIFO


//clase y métodos
class Flanco{
  public:

  // definición de constantes que tendremos disponibles
  static const int BAJADA = -1;
  static const int SUBIDA = 1;
  static const int NO = 0;

  // métodos
  void inicializar(int pin); // configura pin y toma la lectura inicial 
  int detectar();     // método para la detección de flancos
  bool subida();      // método que detecta flanco de subida
  bool bajada();      // método que detecta flanco de bajada
  
  private: 
  // propiedades privadas
  int pin;            // pin vinculado
  int estadoAnterior; // estado del pin en la iteración anterior
};

#endif
