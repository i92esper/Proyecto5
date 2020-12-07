/*
  Fichero: sendero.h
  Descripción: Fichero con los prototipos de las funciones de la clase Sendero
  Autor: Ricardo Espantaleón Pérez
*/
#ifndef SENDERO_H
#define SENDERO_H
#include <string>

using namespace std;

class Sendero{
  private:
    //String que almacena el nombre del sendero
    string nombreSendero_;
    //Entero que almacena el recorrido total en la magnitud Km
    int recorridoTotal_;
  public:
    //Constructor de la clase Sendero para incializar todas las variables de la clase
    Sendero();
    //Void que asigna el nombre del sendero de la instancia
    inline void setNombre_sendero(string nombreSendero){nombreSendero_=nombreSendero;}
    //String que retorna el nombre asignado a la instancia
    inline string getNombre_sendero() const {return nombreSendero_;}
    //Boolean que comprueba que el recorrido se ha asignado a una distancia estrictamente positiva
    bool setRecorrido_total(int recorridoTotal);
    //Entero que retornar el recorrido total asignado a la instancia
    inline int getRecorrido_total() const {return recorridoTotal_;}
};

#endif
