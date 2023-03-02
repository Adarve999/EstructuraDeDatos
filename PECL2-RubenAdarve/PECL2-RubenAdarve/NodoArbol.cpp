#include "NodoArbol.h"

NodoArbol::NodoArbol(Vehiculo dato)
{
	this->dato = dato;
	this->izq = nullptr;
	this->der = nullptr;
}
NodoArbol::~NodoArbol()
{
}
