/*  Detector de flancos
 * 
 *  -- Fichero con código --
 *  
 *  Autor: Robert Sallent 
 *  Curso: programación de placas robóticas en CIFO Sabadell 
 *  Versión: 1.0.0 
 *  
 */
 
#include <Arduino.h>
#include "Flanco.h"

//implementación de los métodos de la clase Flanco

void Flanco::inicializar(int pin){
  this->pin = pin;
	this->estadoAnterior = digitalRead(this->pin);
}

int Flanco::detectar(){
  int estadoActual = digitalRead(this->pin);
  int resultado = Flanco::NO;
  
  if(this->estadoAnterior != estadoActual){
    resultado = estadoActual ? Flanco::SUBIDA : Flanco::BAJADA;
    this->estadoAnterior = estadoActual;
  } 
  return resultado;
}

bool Flanco::subida(){
  return this->detectar() == Flanco::SUBIDA;
}

bool Flanco::bajada(){
  return this->detectar() == Flanco::BAJADA;
}
