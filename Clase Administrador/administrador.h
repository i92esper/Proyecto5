#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Administrador{
private:
  string usuario_;
  string codigo_;
public:
Administrador(string usuario,string codigo){
usuario_=usuario;
codigo_=codigo;
}
bool iniciarSesion(vector <Administrador> a);
void cerrarSesion();
int verificarUsuario(vector <Administrador> a);
inline string getUsuario(){return usuario_;};
inline string getCodigo(){return codigo_;};
inline void setCodigo(string codigo){codigo_=codigo;};
inline void setUsuario(string usuario){usuario_=usuario;};
};
#endif
