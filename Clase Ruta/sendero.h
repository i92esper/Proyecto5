#ifndef SENDERO_H
#define SENDERO_H
#include <string>

using namespace std;

class Sendero{
  private:
    string nombreSendero_;
    int recorridoTotal_;
  public:
    Sendero();
    inline void setNombre_sendero(string nombreSendero){nombreSendero_=nombreSendero;}
    inline string getNombre_sendero() const {return nombreSendero_;}
    bool setRecorrido_total(int recorridoTotal);
    inline int getRecorrido_total() const {return recorridoTotal_;}
};

#endif
