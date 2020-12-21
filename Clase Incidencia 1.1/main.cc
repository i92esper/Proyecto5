#include "incidencia.h"
#include <vector>
#include <string>
int main(){
Incidencia test;
test.setIncidencia(0,"El monitor no podía atender");
vector <Incidencia> v;
v.push_back(test);
test.eliminarIncidencia(v);
}
