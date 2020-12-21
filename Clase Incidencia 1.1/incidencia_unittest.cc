#include "gtest/gtest.h"
#include <iostream>
#include "incidencia.h"
#include <vector>
#include <string>
using namespace std;
TEST(Incidencia,eliminarIncidencia){
  Incidencia test,test2;
  EXPECT_TRUE(test.setIncidencia(0,"El monitor no podia atender"));
  EXPECT_EQ("El monitor no podia atender",test.getinforme());
  vector <Incidencia> v;
  v.push_back(test);
  v=test.eliminarIncidencia(v);
  EXPECT_EQ(0,v.size());
}
TEST(Incidencia,Informe){
Incidencia test,test2;
EXPECT_TRUE(test.setIncidencia(1,"El cliente no aparece"));
EXPECT_FALSE(test2.setIncidencia(2,""));
}
