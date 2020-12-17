#include <iostream>
#include <vector>
#include "incidencia.h"
using namespace std;

    bool Incidencia::setIncidencia(int tipo_incidencia, string informe){
if(!setInforme(informe)){return false;}
if(!settipo_incidencia(tipo_incidencia)){return false;}
return true;
}

void Incidencia::notificaIncidencia(){
  cout<<"Hay una nueva incidencia";
}
void Incidencia::eliminarIncidencia(vector <Incidencia> v){
for(vector <Incidencia>:: iterator it=v.end();it!=v.begin();it--){
    if(informe_.compare(it->getinforme())==0){
      it->setResuelta();
      v.erase(it);}
    }
  }
bool Incidencia::setInforme(string informe){
  if(informe==""){return false;}
    informe_=informe;
    return true;
}
bool Incidencia::settipo_incidencia(int tipo){
  tipo_incidencia_=tipo;
  return true;
}
