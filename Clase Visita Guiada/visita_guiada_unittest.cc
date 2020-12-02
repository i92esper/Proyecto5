/*
  Fichero: visita_guiada_unittest.cc
  Descripción: fichero con los test de la clase Visita Visita guiada
  Autor: Ricardo Espantaleón Pérez
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
}

TEST(Visita_guiada, setRuta{

}
