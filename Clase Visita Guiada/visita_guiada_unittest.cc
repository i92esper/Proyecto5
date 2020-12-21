/*
  Fichero: visita_guiada_unittest.cc
  Descripción: fichero con los test de la clase Visita Visita guiada.
  Autor: Ricardo Espantaleón Pérez.
*/
#include "gtest/gtest.h"
#include "visita_guiada.h"
#include <ctime>

using namespace std;

TEST(Visita_guiada, crearVisita){ //Creación correcta de la visita guiada
  Visita_guiada prueba;
  tm fecha;
  fecha.tm_year=2020;
  fecha.tm_mon=11;
  fecha.tm_mday=20;
  string dni="31478961B";
  int ruta=2;
  string monitor="41087678C";
  EXPECT_TRUE(prueba.crearVisita(fecha,dni,ruta,monitor));
  EXPECT_FALSE(prueba.crearVisita(fecha,dni,10,monitor));
}

TEST(Visita_guiada, setRuta){ //Ruta valida para la visita
  Visita_guiada prueba;
  EXPECT_FALSE(prueba.setRuta(6));
  EXPECT_FALSE(prueba.setRuta(0));
  EXPECT_TRUE(prueba.setRuta(3));
}

TEST(Visita_guiada, setRealizada){ // Visita realizada o cancelada por el visitante correctamente
  Visita_guiada prueba;
  EXPECT_EQ(CREATED,prueba.getRealizada());
  tm fecha;
  fecha.tm_year=2020;
  fecha.tm_mon=11;
  fecha.tm_mday=20;
  string dni="31478961B";
  int ruta=2;
  string monitor="41087678C";
  prueba.crearVisita(fecha,dni,ruta,monitor);
  EXPECT_EQ(VERIFIED,prueba.getRealizada());
  prueba.setRealizada();
  EXPECT_EQ(DONE,prueba.getRealizada());
  prueba.eliminarVisita();
  EXPECT_EQ(DELETED,prueba.getRealizada());
}

TEST(Visita_guiada, Fechavalida){ //Antelacion de dos meses, superior o igual a la actual
  Visita_guiada prueba;
  EXPECT_FALSE(prueba.modificarVisita(10));
  EXPECT_TRUE(prueba.modificarVisita(3));
  tm fecha;
  fecha.tm_year=1900;
  fecha.tm_mon=11;
  fecha.tm_mday=20;
  EXPECT_FALSE(prueba.modificarVisita(fecha)); //Error a la hora de meter una fecha invalida
  fecha.tm_year=2020;
  EXPECT_TRUE(prueba.modificarVisita(fecha));
}

TEST(Visita_guiada, visitantesMaximo){ //Numero de visitantes maximo permitido
  Visita_guiada prueba;
  EXPECT_FALSE(prueba.setNvisitantes(-5));
  EXPECT_FALSE(prueba.setNvisitantes(12));
  EXPECT_TRUE(prueba.setNvisitantes(5));
  EXPECT_EQ(prueba.getNvisitantes(),5);
}

TEST(Visita_guiada, creacionID){ //Creacion de un ID asignado a cada visita
  Visita_guiada prueba;
  tm fecha;
  fecha.tm_year=2020;
  fecha.tm_mon=11;
  fecha.tm_mday=20;
  string dni="31478961B";
  int ruta=2;
  string monitor="41087678C";
  prueba.crearVisita(fecha,dni,ruta,monitor);
  string id;
  id=prueba.getID();
  EXPECT_EQ(5,id.size());
}

TEST(Visita_guiada, borrarVisitas){ //Borrar las instancias de visitas con la funcion friend de la clase 
  vector <Visita_guiada> v;
  Visita_guiada v1, v2, v3;
  tm fecha;
  fecha.tm_year=2020;
  fecha.tm_mon=11;
  fecha.tm_mday=20;
  string dni="31478961B";
  int ruta=2;
  string monitor="41087678C";
  v1.crearVisita(fecha,dni,ruta,monitor);
  v2.crearVisita(fecha,dni,ruta,monitor);
  v3.crearVisita(fecha,dni,ruta,monitor);
  v2.eliminarVisita();
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  borrarVisitas(v);
  EXPECT_EQ(2,v.size());
}

