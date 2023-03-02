#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include <iostream>
#include "Vehiculo.h"
#include "NodoPila.h"
using namespace std;

class NodoCola {
public:
    NodoCola(Vehiculo p, NodoCola* sig = NULL);
    ~NodoCola();
private:

    Vehiculo valor;
    NodoCola* siguiente;
    friend class Cola;

};
typedef NodoCola* pnodoCola;
#endif