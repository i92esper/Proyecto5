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
  a.eliminarVisita();
}
