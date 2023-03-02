#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iostream>
#include "Vehiculo.h"

class NodoArbol
{
public:
	NodoArbol(Vehiculo dato);
	Vehiculo dato;
	~NodoArbol();
private:
	NodoArbol* izq;
	NodoArbol* der;

	friend class Arbol;
};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP
