#include <iostream>
#include <vector>
#include "incidencia.h"
using namespace std;
Incidencia Incidencia::getIncidencia(){
Incidencia a(gettipo_incidencia(),getinforme());
return a;
}
 Incidencia Incidencia::setIncidencia(){
  cout<<"Introduce un tipo de error\n1.Cancelacion\n2.no presentado\n3.otro\n"<<endl;
  int a;
  do{
  cin>>a;
}while(a>3&&a<1);
  cout<<"\nIntroduce el informe de la incidencia\n"<<endl;
  string s;
  cin>>s;
  Incidencia i(a,s);
  return i;
}

void Incidencia::notificaIncidencia(){
  cout<<"Hay una nueva incidencia";
}
void Incidencia::eliminarIncidencia(vector <Incidencia> v,Incidencia i){
  for(vector <Incidencia>:: iterator it=v.begin();it!=v.end();it++){
    if(i.informe_.compare(it->getinforme())==0){
      it->resuelta_==true;
      v.erase(it);
    }
  }

}
