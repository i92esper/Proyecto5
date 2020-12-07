/*
  Fichero: sendero_unittest.cc
  Descripción: fichero con los test de la clase Sendero
  Autor: Ricardo Espantaleón Pérez
*/
#include "gtest/gtest.h"
#include "sendero.h"

using namespace std;

TEST(Sendero, setNombre){
  Sendero prueba;
  EXPECT_EQ("",prueba.getNombre_sendero());
  prueba.setNombre_sendero("Nombre1");
  EXPECT_EQ("Nombre1",prueba.getNombre_sendero());
}

TEST(Sendero, setRecorrido){
  Sendero prueba;
  prueba.setRecorrido_total(-34);
  EXPECT_EQ(-1,prueba.getRecorrido_total());
  prueba.setRecorrido_total(100);
    EXPECT_EQ(100,prueba.getRecorrido_total());
}
