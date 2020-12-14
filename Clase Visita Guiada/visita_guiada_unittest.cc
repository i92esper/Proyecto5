/*
  Fichero: visita_guiada_unittest.cc
  Descripción: fichero con los test de la clase Visita Visita guiada.
  Autor: Ricardo Espantaleón Pérez.
*/
#include "gtest/gtest.h"
#include "visita_guiada.h"
#include <ctime>

using namespace std;

TEST(Visita_guiada, crearVisita){
  Visita_guiada prueba;
  tm fecha;
  fecha.tm_year=2020;
  fecha.tm_mon=11;
  fecha.tm_mday=20;
  string dni="31478961B";
  int ruta=2;
  string monitor="Nicolás";
  EXPECT_TRUE(prueba.crearVisita(fecha,dni,ruta,monitor));
  EXPECT_FALSE(prueba.crearVisita(fecha,dni,10,monitor));
}

TEST(Visita_guiada, setRuta){
  Visita_guiada prueba;
  EXPECT_FALSE(prueba.setRuta(6));
  EXPECT_FALSE(prueba.setRUta(0));
  EXPECT_TRUE(prueba.setRuta(3));
}

TEST(Visita_guiada, setRealizada){
  Visita_guiada prueba;
  EXPECT_EQ(CREATED,prueba.getRealizada());
  tm fecha;
  fecha.tm_year=2020;
  fecha.tm_mon=11;
  fecha.tm_mday=20;
  string dni="31478961B";
  int ruta=2;
  string monitor="Nicolás";
  prueba.crearVisita(fecha,dni,ruta,monitor);
  EXPECT_EQ(VERIFIED,prueba.getRealizada());
  prueba.setRealizada();
  EXPECT_EQ(DONE,prueba.getRealizada());
  prueba.eliminarVisita();
  EXPECT_EQ(DELETED,prueba.getRealizada());
}

TEST(Visita_guiada, modificarVisita){
  Visita_guiada prueba;
  EXPECT_FALSE(prueba.modificarVisita(10));
  EXPECT_TRUE(prueba.modificarVisita(3));
  tm fecha;
  fecha.tm_year=2001;
  fecha.tm_mon=11;
  fecha.tm_mday=20;
  EXPECT_FALSE(prueba.modificarVisita(fecha));
  fecha.tm_year=2020;
  EXPECT_TRUE(prueba.modificarVisita(fecha));
}
