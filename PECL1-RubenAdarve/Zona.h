#pragma once
#include "Vehiculo.h"
#include "Cola.h"
#include "Pila.h"
class Zona
{
public:
	Zona();
	Pila camion_1;
	Pila camion_2;
	Cola cola;
	bool control;

	void apilarCamion1(Vehiculo v);
	void apilarCamion2(Vehiculo v);

	void vaciarCamion1(int  concesionarios);
	void vaciarCamion2(int  concesionarios);

	void limpiarCamion1(int  concesionarios);
	void limpiarCamion2(int  concesionarios);

	void seleccionCamion(int tamanoCamion, Vehiculo v);
};

