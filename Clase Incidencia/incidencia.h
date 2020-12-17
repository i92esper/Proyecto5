#ifndef INCIDENCIA_H
#define INCIDENCIA_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Incidencia{
private:
  //entero que define los tipos de incidencia
  int tipo_incidencia_;
  //informe de la incidencia
  string informe_;
  //boolean que define si esta resuelta o no
  bool resuelta_;
public:
  Incidencia(){
    tipo_incidencia_=-1;
    informe_="";
    resuelta_=false;}
  //gets y sets
  inline int gettipo_incidencia(){return tipo_incidencia_;};
  inline string getinforme(){return informe_;};
  Incidencia getIncidencia();
  bool setIncidencia(int tipo_incidencia, string informe);
  //notifica de la llegada de una incidencia
  void notificaIncidencia();
  //elimina una incidencia de un vector 
  void eliminarIncidencia(vector <Incidencia> v);
  //más gets y sets
  inline void setResuelta(){resuelta_=true;};
  bool setInforme(string informe);
  bool settipo_incidencia(int tipo);

};
#endif
