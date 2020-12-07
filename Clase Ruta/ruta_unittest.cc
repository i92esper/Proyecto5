/*
  Fichero: ruta_unittest.cc
  Descripción: fichero con los test de la clase Ruta
  Autor: Ricardo Espantaleón Pérez
*/
#include "gtest/gtest.h"
#include "ruta.h"
#include "sendero.h"
#include <vector>

using namespace std;

TEST(Ruta, createRutaTrue){
  Ruta prueba;
  vector<Sendero> senderos(3);
  senderos[0].setNombre_sendero("Sendero 1");
  senderos[1].setNombre_sendero("Sendero 2");
  senderos[2].setNombre_sendero("Sendero 3");
  EXPECT_TRUE(prueba.crearRuta(2,"El colorado",'M',senderos));
}

TEST(Ruta, createRutaFalse){
  Ruta prueba;
  vector<Sendero> senderos(3);
  senderos[0].setNombre_sendero("Sendero 1");
  senderos[1].setNombre_sendero("Sendero 2");
  senderos[2].setNombre_sendero("Sendero 3");
  EXPECT_FALSE(prueba.crearRuta(2,"El colorado",'z',senderos));
}

TEST(Ruta, setRuta){
  Ruta prueba;
  EXPECT_TRUE(prueba.setTipo_ruta(2));
  EXPECT_FALSE(prueba.setTipo_ruta(4));
}

TEST(Ruta, setDificultad){
  Ruta prueba;
  EXPECT_TRUE(prueba.setDificultad('m'));
  EXPECT_FALSE(prueba.setDificultad('J'));
}

TEST(Ruta, setSenderos){
  Ruta prueba;
  vector<Sendero> senderos(9);
  EXPECT_FALSE(prueba.setSenderos(senderos));
  senderos.resize(5);
  EXPECT_TRUE(prueba.setSenderos(senderos));
}
