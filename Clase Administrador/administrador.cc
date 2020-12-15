#include <vector>
#include <iostream>
#include "monitor.h"
#include <string>
#include "visita_guiada.h"
#include "administrador.h"
using namespace std;

bool Administrador::iniciarSesion(vector <Administrador> a){
  for(vector <Administrador>::iterator i=a.begin();i!=a.end();i++){
    if(usuario_.compare(i->getUsuario())==0 && codigo_.compare(i->getCodigo())==0){
  return true;}
}
return false;
}
void Administrador::cerrarSesion(){exit(-1);};

void Administrador::verificarUsuario(vector <Administrador> a,Administrador b){
    a.push_back(b);
}
