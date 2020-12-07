/*
  Fichero: visita_guiada.h
  Descripción: fichero .h de los prototipos de la clase Visita guiada
  Autor: Ricardo Espantaleón Pérez
*/
#ifndef VISITA_GUIADA_H
#define VISITA_GUIADA_H
#include <string>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
/*Enum donde se enumeran los estados que pueden tener una visita:
DELETED->La visita ha sido eliminada para su posterior borrado logico
CREATED->Visita creada
VERIFIED->Visita verificada en el sistema lista para realizarse
DONE->Visita realizada lista para eliminarse del sistema para su posterior borrado lógico
*/
enum done{DELETED=-2, CREATED=-1, VERIFIED=0, DONE=1};
enum ret{FAILURE=-1, SUCCESS=0};

class Visita_guiada{
  private:
    //ID asignado a la instancia de la visita
    string id_;
    //Dato de tipo date asignado a la visita
    tm fecha_;
    //enumeracion done que indica si la instancia ha sido borrada, creada, verificada y realizada
    done estado_;
    //DNI del visitante que ha reservado la visita
    string dni_;
    //Crear clase ruta, debera comprobar si la ruta introducida corresponde a una ruta existente
    int ruta_;
    //Crear clase monitor, para asi comprobar si esta identificado en el sistema, y asi poder asignarlo a la visita
    string monitor_;
  public:
    //Constructor de la clase, inicia la semilla para la generacion del ID de la instancia particular
    Visita_guiada();
    //Funcion booleana que retorna true en caso de que se haya creado la visita correctamente, false en caso contrario
    bool crearVisita(tm fecha, string dni, int ruta, string monitor);
    //Funcion booleana que retorna true en caso de que la ruta corresponda con las rutas dentro del sistema
    bool setRuta(int ruta);
    //Funcion booleana que comprueba que el dni es valido
    bool setDNI(string dni);
    //Funcion booelana que cmprueba que la fecha de reserva de la visita sea apta para el sistema
    bool setFecha(tm &fecha);
    //Funcion booleana que comprueba que el monitor introducido existe dentro del sistema
    bool setMonitor(string monitor);
    //Funcion void que crea un ID alfanumérico asignado a cada visita particular
    inline void createID() {id_=fecha_.tm_mon+fecha_.tm_hour+monitor_[0]+monitor_[monitor_.size()-1];}
    //Funcion string que retorna el ID asignado a la visita
    inline string getID() const {return id_;}
    //Funcion tm que retorna la fecha asignada a la visita
    inline tm getFecha() const {return fecha_;}
    //Funcion string que retornar el DNI del visitante que ha reservado la visita
    inline string getDNI() const {return dni_;}
    //Funcion int que retorna la ruta asignada a la visita guiada
    inline int getRuta() const {return ruta_;}
    //Funcion string que retorna el monitor asignado
    inline string getMonitor() const {return monitor_;}
    //Funcion done que devuelve el estado de la visita guiada
    inline done getRealizada() const {return estado_;}
    //Funcion void que asigna el estado de realizada para su posterior borrado lógico
    inline void setRealizada() {estado_=DONE;}
    //Funcion void que asigna el estado de eliminado para su posterior borrado lógico
    inline void eliminarVisita() {estado_=DELETED;}
    //Funcion boolean que retorna true si se ha eliminado una visita o mas, y false si no se ha borrado ninguna visita
    friend bool borrarVisitas(vector<Visita_guiada> vg);
    //Funcion boolean que asigna true si se ha podido asignar la nueva fecha deseada
    bool modificarVisita(tm fecha);
    //Funcion boolean que asigna true si se ha podido asignar la nueva ruta deseada
    bool modificarVisita(int ruta);
};

#endif
