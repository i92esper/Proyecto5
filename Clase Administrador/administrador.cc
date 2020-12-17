#include <vector>
#include <iostream>
#include <string>
#include "administrador.h"
using namespace std;

bool Administrador::iniciarSesion(vector <Administrador> a){
  for(vector <Administrador>::iterator i=a.begin();i!=a.end();i++){
    if(usuario_.compare(i->getUsuario())==0 && codigo_.compare(i->getCodigo())==0){
  return true;}
}
return false;
}
void Administrador::cerrarSesion(){exit(-1);}

int Administrador::verificarUsuario(vector <Administrador> a){
    Administrador b(getUsuario(),getCodigo());
    a.push_back(b);
    return a.size();
}
