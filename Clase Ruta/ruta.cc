/*
  Fichero: ruta.cc
  Descripción: fichero con los cuerpos de procedimiento de los métodos de la clase Ruta
  Autor: Ricardo Espantaleón Pérez
*/
#include "ruta.h"

Ruta::Ruta(){
  tipoRuta_=0;
  nombreRuta_="";
  dificultad_=' ';
  senderos_.resize(0);
}

bool Ruta::crearRuta(int tipoRuta, string nombreRuta, char dificultad, vector<Sendero> &senderos){
  if(!setTipo_ruta(tipoRuta))
    return false;
  nombreRuta_=nombreRuta;
  if(!setDificultad(dificultad))
    return false;
  if(!setSenderos(senderos))
    return false;
  return true;
}

bool Ruta::setTipo_ruta(int tipoRuta){
  if(tipoRuta < 1 || tipoRuta > 3)
    return false;
  tipoRuta_=tipoRuta;
  return true;
}

bool Ruta::setDificultad(char dificultad){
  if(toupper(dificultad) != 'F' && toupper(dificultad) != 'M' && toupper(dificultad) != 'D')
    return false;
  dificultad_=dificultad;
  return true;
}

bool Ruta::setSenderos(vector<Sendero> &senderos){
  if(senderos.size() > 8){
    return false;
  }
  for(int i=0; i<senderos.size(); ++i){
    senderos_.push_back(senderos[i]);
  }
  return true;
}
