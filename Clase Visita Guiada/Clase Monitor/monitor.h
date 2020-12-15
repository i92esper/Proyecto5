//Monitor.cc, por Nicolas Lopez
#ifndef MONITOR_H
#define MONITOR_H
#include <list>
#include <iostream>
#include "visita_guiada.h"
#include <string>
using namespace std;
class Monitor{
private:
  string nombre_completo_;
  string DNI_;
  string usuario_;
  list <Visita_guiada> visitas_asignadas_;
public:
  void getHorario(vector <Visita_guiada> vg);
  void confirmarAsistencia(Visita_guiada &a);
  bool identificacion(string dni_,vector <string> v);
  inline string getDNI(){return DNI_;}
};
#endif
