#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "administrador.h"
using namespace std;

TEST(Administrador,iniciarSesion){
Administrador test("Antonio López","37119"),test2("Diego Mota","77777");
vector <Administrador> v;
v.push_back(test);

EXPECT_TRUE(test.iniciarSesion(v));
EXPECT_FALSE(test2.iniciarSesion(v));
}

TEST(Administrador,verificarUsuario){
  Administrador test("Iker Casillas","111213");
  vector <Administrador> v;
  test.verificarUsuario(v);
  EXPECT_EQ(1,test.verificarUsuario(v));
}
