//administrador, por Nicolas Lopez
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Administrador{
private:
  //nombre del administrador
  string usuario_;
  //codigo de identificacion
  string codigo_;
public:
//constructor básico
  Administrador(string usuario,string codigo){
usuario_=usuario;
codigo_=codigo;
}
  //inicia la sesion si el nombre está en el vector
bool iniciarSesion(vector <Administrador> a);
//termina la ejecucción del programa
  void cerrarSesion();
//mete un elemento en el vector
  int verificarUsuario(vector <Administrador> a);
//serie de gets y sets
 inline string getUsuario(){return usuario_;};
inline string getCodigo(){return codigo_;};
inline void setCodigo(string codigo){codigo_=codigo;};
inline void setUsuario(string usuario){usuario_=usuario;};
};
#endif
