#ifndef INCIDENCIA_H
#define INCIDENCIA_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Incidencia{
private:
  int tipo_incidencia_;
  string informe_;
  bool resuelta_;
public:
  Incidencia(int tipo,string informe){
    tipo_incidencia_=tipo;
    informe_=informe;
    resuelta_=false;}
  inline int gettipo_incidencia(){return tipo_incidencia_;};
  inline string getinforme(){return informe_;};
  Incidencia getIncidencia();
  Incidencia setIncidencia();
  void notificaIncidencia();
  void eliminarIncidencia(vector <Incidencia> v,Incidencia i);
};
#endif
