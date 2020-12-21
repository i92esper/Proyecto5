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
  Incidencia(){
    tipo_incidencia_=-1;
    informe_="";
    resuelta_=false;}
  inline int gettipo_incidencia(){return tipo_incidencia_;};
  inline string getinforme(){return informe_;};
  Incidencia getIncidencia();
  bool setIncidencia(int tipo_incidencia, string informe);
  void notificaIncidencia();
  vector <Incidencia> eliminarIncidencia(vector <Incidencia> v);
  inline void setResuelta(){resuelta_=true;};
  bool setInforme(string informe);
  bool settipo_incidencia(int tipo);
  inline bool getResuelta(){return resuelta_;};
};
#endif
