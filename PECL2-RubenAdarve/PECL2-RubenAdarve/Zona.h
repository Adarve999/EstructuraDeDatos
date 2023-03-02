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

	void vaciarCamion1();
	void vaciarCamion2();

	void limpiarCamion1();
	void limpiarCamion2();

	void seleccionCamion(int tamanoCamion, Vehiculo v);
};

