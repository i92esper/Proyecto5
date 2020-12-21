//Monitor.cc, por Nicolas Lopez

#include <list>
#include <vector>
#include "visita_guiada.h"
#include "monitor.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
//definimos el punter ode tm que teendrá la hora local
tm * lotm;
Monitor::Monitor(){
  time_t now=time(NULL);
  lotm=localtime(&now);
  nombre_completo_="";
  DNI_="";
  estado_=false;
  fecha_.tm_year=0;
  fecha_.tm_mon=0;
  fecha_.tm_mday=0;

  visitas_asignadas_.clear();

}
bool Monitor::setDNI(string dni){
  DNI_=dni;
  return true;
}
bool Monitor::identificacion(vector <string> v){
for (vector<string>::iterator i=v.begin();i!=v.end();i++){
string a=getDNI(),b=*i;
if(b.compare(a)==0){
  return true;}
}
return false;
}
void Monitor::getHorario(vector <Visita_guiada> vg){
for (vector<Visita_guiada>::iterator i=vg.begin();i!=vg.end();i++){
string a=getDNI(),b=i->getMonitor();
if(b.compare(a)==0 && setFecha(fecha_)){
    visitas_asignadas_.push_back(*i);}
  }
}

void Monitor::confirmarAsistencia(Visita_guiada &a){
  a.setRealizada();
}
bool Monitor::setFecha(tm fecha){
if(fecha.tm_year < lotm->tm_year){return false;}
if (fecha.tm_mon < lotm->tm_mon && fecha.tm_year == lotm->tm_year){return false;}
if(fecha.tm_mon == lotm->tm_mon && fecha.tm_year == lotm->tm_year && fecha.tm_mday < lotm->tm_mday){return false;}
fecha_=fecha;
return true;
}
bool Monitor::crearMonitor(string nombre,string dni,tm fecha){
nombre_completo_=nombre;
if(!setDNI(dni)) {return false;}
DNI_=dni;
if(!setFecha(fecha)){return false;}
fecha_=fecha;
estado_=true;
return true;
};
