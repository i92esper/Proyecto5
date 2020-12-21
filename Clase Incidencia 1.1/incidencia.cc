#include <iostream>
#include <vector>
#include "incidencia.h"
#include <string>
using namespace std;

    bool Incidencia::setIncidencia(int tipo_incidencia, string informe){
if(!setInforme(informe)){return false;}
if(!settipo_incidencia(tipo_incidencia)){return false;}
return true;
}

void Incidencia::notificaIncidencia(){
  cout<<"Hay una nueva incidencia";
}
vector <Incidencia> Incidencia::eliminarIncidencia(vector <Incidencia> v){
int n=v.size();
for(int i=0;i<v.size();i++){

  if(v[i].getinforme()==informe_){

    setResuelta();
    v[i]=v[i+1];
    v.resize(n-1);
    }
    }
    return v;
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
