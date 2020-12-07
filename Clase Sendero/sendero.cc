/*
  Fichero: sendero.cc
  Descripción: fichero con los cuerpos de procedimiento de los métodos de la clase Sendero
  Autor: Ricardo Espantaleón Pérez
*/
#include "sendero.h"

Sendero::Sendero(){
  nombreSendero_="";
  recorridoTotal_=-1;
}

bool Sendero::setRecorrido_total(int recorridoTotal){
  if(recorridoTotal < 1)
    return false;
  recorridoTotal_=recorridoTotal;
  return true;
}
