//Monitor.cc, por Nicolas Lopez

#include <list>
#include <vector>
#include "visita_guiada.h"
#include "monitor.h"
#include <string>
#include <iostream>
using namespace std;
bool Monitor::identificacion(string dni_,vector <string> v){
for (vector<string>::iterator i=v.begin();i!=v.end();i++){
string a=getDNI(),b=*i;
if(b.compare(a)==0){return true;}
}
return false;
}
void Monitor::getHorario(vector <Visita_guiada> vg){
for (vector<Visita_guiada>::iterator i=vg.begin();i!=vg.end();i++){
string a=getDNI(),b=i.getMonitor();
if(b.compare(a)==0){
    visitas_asignadas_.push_back(i)}
  }
}

void Monitor::confirmarAsistencia(Visita_guiada &a){
  a.getRealizada();
char arr1 [23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
bool Monitor::setDNI(string dni){
  int numeros=stoi(dni);
  if(arr1[numeros%23] != dni[dni.size()-1]){
  return false;}
  DNI_=dni;
  return true;
}
