#include "gtest/gtest.h"
#include "monitor.h"
#include "visita_guiada.h"
#include <ctime>
#include <vector>
#include <list>
#include <string>
using namespace std;
//prueba que se recojan las visitas asignadas a ese dni
TEST(Monitor,getHorario){
  Monitor test;
  Visita_guiada a;
  tm fecha;
  fecha.tm_year=2020;
  fecha.tm_mon=12;
  fecha.tm_mday=25;
  test.crearMonitor("Pepito","31023573T",fecha);
  a.crearVisita(fecha,"31478961B",1,"31023573T");
  vector <Visita_guiada> v;
  v.push_back(a);
  test.getHorario(v);
  EXPECT_EQ(1,test.getvisitas_asignadas_size());
}
//prueba que se cree correctamente el usuario
TEST(Monitor,estado){
  Monitor test,test2;
  tm fecha;
  fecha.tm_year=2020;
  fecha.tm_mon=11;
  fecha.tm_mday=25;
  test.crearMonitor("31023573T","Alfonso",fecha);
  EXPECT_TRUE(test.getEstado());
  EXPECT_FALSE(test2.getEstado());

}


//comprueba que se cambie el estado de una visita concreta a done
TEST(Monitor,confirmarAsistencia){
Visita_guiada a;
tm fecha;
fecha.tm_year=2020;
fecha.tm_mon=12;
fecha.tm_mday=17;
Monitor test;
test.crearMonitor("31023573T","Alfonso",fecha);
  a.crearVisita(fecha,"31478961B",1,"31023573T");
test.confirmarAsistencia(a);
  EXPECT_EQ(DONE,a.getRealizada());

}
//comprueba que funcione la identificacion comparando un dni con un vector de dnis
TEST(Monitor,identificacion){
  tm fecha;
  fecha.tm_year=2020;
  fecha.tm_mon=12;
  fecha.tm_mday=25;
  Monitor test;
  EXPECT_TRUE(test.crearMonitor("31023573T","Alfonso",fecha));
  Monitor test2;
  EXPECT_TRUE(test2.crearMonitor("31478961B","Jose",fecha));
  vector <string> a;
  Monitor test3;
  a.push_back(test.getDNI());
  a.push_back(test2.getDNI());
  EXPECT_TRUE(test.identificacion(a)) ;
  EXPECT_FALSE(test3.identificacion(a));
}
