/*
  Fichero: visita_guiada.cc
  Descripción: Fichero con los procedimientos de las operaciones de la clase Visita_guiada
  Autor: Ricardo Espantaleón Pérez
*/
#include "visita_guiada.h"

//Arreglo con las letras del DNI para hacer las correspondientes comprobaciones
char arr1 [23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
//Macro SYSDATE del sistema
tm * ltm;

Visita_guiada::Visita_guiada(){
  time_t now=time(NULL);
  ltm=localtime(&now);
  estado_=CREATED;
  ruta_=0;
  monitor_="";
  dni_="";
  fecha_.tm_year=1970;
  fecha_.tm_mon=1;
  fecha_.tm_mday=1;
  id_.resize(5);
  id_="";
  nvisitantes_=0;
}

bool Visita_guiada::crearVisita(tm fecha, string dni, int ruta, string monitor){
  if(!setFecha(fecha))
    return false;
  if(!setDNI(dni))
    return false;
  if(!setRuta(ruta))
    return false;
  if(!setMonitor(monitor))
    return false;
  estado_=VERIFIED;
  createID();
  return true;
}

bool Visita_guiada::setFecha(tm &fecha){
  if(fecha.tm_mon-ltm->tm_mon > 2)
    return false;
  if(fecha.tm_year < ltm->tm_year)
    return false;
  fecha_=fecha;
  return true;
}

bool Visita_guiada::setDNI(string dni){
  int numeros=stoi(dni);
  if(arr1[numeros%23] != dni[dni.size()-1])
    return false;
  return true;
}

bool Visita_guiada::setRuta(int ruta){
  if(ruta<1 || ruta>5)
    return false;
  ruta_=ruta;
  return true;
}

bool Visita_guiada::setMonitor(string monitor){
  monitor_=monitor;
  return true;
}
//Borro las visitas pasando por referencia el objeto vector, para aplicar los cambios sobre el vector de visitas
bool borrarVisitas(vector<Visita_guiada> &vg){
  int flag=false;
  for(unsigned int i=0; i<vg.size(); ++i){
    if(vg[i].estado_==DONE || vg[i].estado_==DELETED){
      vg.erase(vg.begin()+i);
      flag=true;
    }
  }
  return flag;
}

bool Visita_guiada::modificarVisita(int ruta){
  if(!setRuta(ruta))
    return false;
  return true;
}

bool Visita_guiada::modificarVisita(tm &fecha){
  if(!setFecha(fecha))
    return false;
  return true;
}

bool Visita_guiada::setNvisitantes(int nvisitantes){
  if(nvisitantes < 1 || nvisitantes > 10)
    return false;
  nvisitantes_=nvisitantes;
  return true;
}

void Visita_guiada::createID(){
  for(int i=0; i<5; ++i){
    id_=id_+arr1[rand()%23];
  }
}
