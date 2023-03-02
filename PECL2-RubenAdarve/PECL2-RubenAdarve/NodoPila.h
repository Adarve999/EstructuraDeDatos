#ifndef NODOPILA_HPP
#define NODOPILA_HPP
#include <iostream>
#include "Vehiculo.h"
using namespace std;

class NodoPila
{
public:

	NodoPila(Vehiculo p, NodoPila* sig = NULL);
	~NodoPila();

private:
	Vehiculo valor;
	NodoPila* siguiente;
	friend class Pila;
};
typedef NodoPila* pnodoPila;
#endif









