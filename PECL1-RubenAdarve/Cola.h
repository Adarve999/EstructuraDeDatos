#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.h"
#include "NodoPila.h"
#include "Vehiculo.h"
class Cola {
public:
	Cola();
	~Cola();
	void insertar(Vehiculo p);
	void mostrar();
	Vehiculo eliminar();
	Vehiculo verPrimero();
	int getLongitud();
	void mostrar_cola();
	void borrar_cola();

private:
	pnodoCola primero, ultimo;
	int longitud;
};
#endif