//Monitor.cc, por Nicolas Lopez
#ifndef MONITOR_H
#define MONITOR_H
#include <list>
#include <iostream>
#include "visita_guiada.h"
#include <string>
#include <ctime>
using namespace std;
class Monitor{
private:
//variable nombre y dni, identificadores
  string nombre_completo_;
  string DNI_;
//lista con las visitas del monitor
  list <Visita_guiada> visitas_asignadas_;
//boolean que define si el monitor está correctamente creado
  bool estado_;
  //fecha de inicio de sesion (siempre igual o mayor a la fecha actual)
  tm fecha_;
public:
//iniciador sencillo
  Monitor();
  //crea un monitor con estableciendo sus variables y comprobando que sean correctas
  bool crearMonitor(string nombre,string dni,tm fecha);
  //mete en la lista las visitas asignadas por dni al monitor
  void getHorario(vector <Visita_guiada> vg);
  //confirma que una visita x ha sido realizada
  void confirmarAsistencia(Visita_guiada &a);
  //el monitor se identifica con su nombre y su dni y si es correcto entra en el sistema
  bool identificacion(vector <string> v);
  //serie de sets y gets varios
  inline string getDNI(){return DNI_;};
  bool setDNI(string dni);
  inline int getvisitas_asignadas_size(){return visitas_asignadas_.size();}
  inline tm getFecha(){return fecha_;};
  bool setFecha(tm fecha);
  inline bool getEstado(){return estado_;};
};
#endif
