#include "sendero.h"

Sendero::Sendero(){
  nombreSendero_="";
  recorridoTotal_=-1;
}

bool Sendero::setRecorrido_total(int recorridoTotal){
  if(recorridoTotal < 1)
    return false;
  recorridoTotal_=recorridoTotal;
  return true;
}
