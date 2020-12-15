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
fecha_=localtime(&now);
id_="";
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
return true;
}

bool Visita_guiada::setFecha(tm &fecha){
if(ltm->tm_mon > fecha.tm_mon)
  return false;
if(fecha.tm_mon-ltm->tm_mon > 2)
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

bool borrarVisitas(vector<Visita_guiada> vg){
int flag=false;
for(int i=0; i<vg.size(); ++i){
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

bool Visita_guiada::modificarVisita(tm fecha){
if(!setFecha(fecha))
  return false;
return true;
}
