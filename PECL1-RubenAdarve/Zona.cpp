#include "Zona.h"
#include "Vehiculo.h"
Zona::Zona()
{
	control = false;
}

void Zona::apilarCamion1(Vehiculo v) {
	camion_1.insertar(v);
}

void Zona::apilarCamion2(Vehiculo v) {
	camion_2.insertar(v);
}

void Zona::vaciarCamion1(int  concesionarios) {// si esta lleno vacia el camion
	if (camion_1.getLleno()) {
		while (camion_1.getLongitud() != 0)
		{
			Vehiculo v = camion_1.extraer();
			v.set_concesionario(v.generarConcesionario(concesionarios));
			cola.insertar(v);
		}
		camion_1.setLleno(false);
	}
}

void Zona::vaciarCamion2(int  concesionarios) {//aunque no este lleno vacía los vehiculos que haya en las pilas
	if (camion_2.getLleno()) {
		while (camion_2.getLongitud() != 0)
		{
			Vehiculo v = camion_2.extraer();
			v.set_concesionario(v.generarConcesionario(concesionarios));
			cola.insertar(v);
		}
		camion_2.setLleno(false);
	}
}

void Zona::limpiarCamion1(int  concesionarios) {
	while (camion_1.getLongitud() != 0)
	{
		Vehiculo v = camion_1.extraer();
		v.set_concesionario(v.generarConcesionario(concesionarios));
		cola.insertar(v);
	}
}

void Zona::limpiarCamion2(int  concesionarios) {
	while (camion_2.getLongitud() != 0)
	{
		Vehiculo v = camion_2.extraer();
		v.set_concesionario(v.generarConcesionario(concesionarios));
		cola.insertar(v);
	}
}

void Zona::seleccionCamion(int tamanoCamion, Vehiculo v) {
	if (control == false) {
		if (camion_1.getLongitud() <= tamanoCamion)
		{
			apilarCamion1(v);
			if (camion_1.getLongitud() == tamanoCamion) {
				camion_1.setLleno(true);
				control = true;
			}
		}
	}
	else if (control == true) {
		if (camion_2.getLongitud() <= tamanoCamion) {
			apilarCamion2(v);
			if (camion_2.getLongitud() == tamanoCamion) {
				camion_2.setLleno(true);
				control = false;
			}
		}
	}
}
