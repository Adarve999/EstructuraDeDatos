#ifndef PILA_HPP
#define PILA_HPP
#include "NodoCola.h"
#include "NodoPila.h"
#include "Vehiculo.h"
#include "Cola.h"
class Pila
{
public:
	Pila();
	~Pila();
	void insertar(Vehiculo p);
	Vehiculo extraer();
	Vehiculo cima();
	void mostrar();
	int getLongitud();
	bool getLleno();
	void setLleno(bool);
	void limpiarPila();
private:
	pnodoPila ultimo;
	int longitud;
	bool lleno;
};
#endif // PILA_HPP