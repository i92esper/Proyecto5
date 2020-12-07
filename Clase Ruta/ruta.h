/*
  Fichero: ruta.h
  Descripción: fichero con los prototipos de la clase Ruta
  Autor: Ricardo Espantaleón Pérez
*/
#ifndef RUTA_H
#define RUTA_H
#include <cctype>
#include <vector>
#include "sendero.h"
#include <string>

using namespace std;

class Ruta{
  private:
    //ID asignado a la ruta particular
    int id_;
    //Entero que indica el tipo de ruta, 1 -> Andando, 2 -> Bici y 3 -> Barco
    int tipoRuta_;
    //Nombre asociado a la ruta
    string nombreRuta_;
    //Vector que almacena los senderos en orden de recorrido asignados a la ruta
    vector<Sendero> senderos_;
    //Char que almacena los tres tipos de dificultad que existen en los tipos de ruta, F -> Facil, M -> Medio y D -> Difícil
    char dificultad_;
  public:
    //Constructor de la clase Ruta, para inicializar todas las variables privadas de la clase Ruta
    Ruta();
    //Boolean que retorna true en caso de que la ruta se haya creado correctamente
    bool crearRuta(int tipoRuta, string nombreRuta, char dificultad, vector<Sendero> &senderos);
    //Boolean que retorna true en caso de que se haya asignado uno de los tipos de rutas disponibles en el sistema
    bool setTipo_ruta(int tipoRuta);
    //Bolean que retorna true en caso de que se haya asignado uno de los tipos de dificultades disponibles en el sistema
    bool setDificultad(char dificultad);
    //Boolean que retorna true en caso de que se hayan asignado correctamente los senderos a la instancia de la ruta
    bool setSenderos(vector<Sendero> &senderos);
};

#endif
