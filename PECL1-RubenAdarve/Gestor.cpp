#include "Gestor.h"
#include "Vehiculo.h"
#include "Zona.h"
#include <iostream>
Gestor::Gestor()
{
}
void Gestor::crear_Vehiculos(int nVehiculos)
{
	operacion_CrearVehiculos(nVehiculos);
}

void Gestor::crear_VehiculosPorUsuario(string cadUsuario)
{
	int nVehiculos;
	nVehiculos = stoi(cadUsuario);
	operacion_CrearVehiculos(nVehiculos);
}

void Gestor::operacion_CrearVehiculos(int nVehiculos) {
	cout << "Generados - " << nVehiculos << " coches." << endl;
	for (int i = 0; i < nVehiculos; i++)
	{
		Vehiculo v;
		cola_fabrica.insertar(v);
	}
}

void Gestor::mostrar_cola_fabrica()
{
	cout << "-------------------" << endl;
	cout << "|    Cola Fabrica     |" << endl;;
	cout << "-------------------" << endl;

	cola_fabrica.mostrar_cola();
}

void Gestor::borrar_cola_fabrica()
{
	cola_fabrica.borrar_cola();
}

void Gestor::cargar_Vehiculos(int NS, int tamanoCamion, int concesinarios)
{
	if (cola_fabrica.getLongitud() == 0)
	{
		cout << "La cola de la fabrica esta vacia de coches." << endl;
	}
	else
	{
		if (cola_fabrica.getLongitud() <= NS) { NS = cola_fabrica.getLongitud(); } //para que no crees de más vehiculos
		cargaPilas(NS, tamanoCamion, concesinarios); // metodo para llenar las pilas
		cout << NS << " Vehiculos cargados correctamente." << endl;
	}
}
void Gestor::cargar_VehiculosPorUsuario(string cadUsuario, int tamanoCamion, int concesinarios)
{

	if (cola_fabrica.getLongitud() == 0)
	{
		cout << "La cola de la fabrica esta vacia de coches." << endl;
	}
	else
	{
		int nVehiculos = stoi(cadUsuario);//casteo de string a int
		if (cola_fabrica.getLongitud() <= nVehiculos) { nVehiculos = cola_fabrica.getLongitud(); }//para que no crees de más vehiculos
		cargaPilas(nVehiculos, tamanoCamion, concesinarios);  // metodo para llenar las pilas
		cout << nVehiculos << " Vehiculos cargados correctamente." << endl;
	}
}
void Gestor::cargaPilas(int Vehiculos, int tamanoCamion, int concesionarios) {
	int selectorZona;
	string letras[3] = { "A","B","C" };
	for (int i = 0; i < Vehiculos; i++)
	{
		string zona;
		selectorZona = rand() % 3;
		zona = letras[selectorZona];
		switch (zona[0])
		{
		case('A'):
			zonaA.seleccionCamion(tamanoCamion,cola_fabrica.eliminar());
			break;
		case('B'):
			zonaB.seleccionCamion(tamanoCamion, cola_fabrica.eliminar());
			break;
		case('C'):
			zonaC.seleccionCamion(tamanoCamion, cola_fabrica.eliminar());
			break;
		}

	}
	zonaA.vaciarCamion1(concesionarios);
	zonaA.vaciarCamion2(concesionarios);

	zonaB.vaciarCamion1(concesionarios);
	zonaB.vaciarCamion2(concesionarios);

	zonaC.vaciarCamion1(concesionarios);
	zonaC.vaciarCamion2(concesionarios);
}

void Gestor::mostrar_cola_zonas_Y_pilas() {
	cout << endl;
	cout << "-------------------" << endl;
	cout << "|     ZONA A      |" << endl;
	cout << "-------------------" << endl;
	cout << "Camion A - 1" << endl;
	cout << endl;
	zonaA.camion_1.mostrar();
	cout << "Camion A - 2" << endl;
	cout << endl;
	zonaA.camion_2.mostrar();
	cout << endl;
	cout << "-------------------" << endl;
	cout << "|    Cola Zona A     |" << endl;;
	cout << "-------------------" << endl;
	cout << endl;
	zonaA.cola.mostrar_cola();
	cout << endl;

	cout << "-------------------" << endl;
	cout << "|     ZONA B      |" << endl;
	cout << "-------------------" << endl;
	cout << "Camion B - 1" << endl;
	cout << endl;
	zonaB.camion_1.mostrar();
	cout << "Camion B - 2" << endl;
	cout << endl;
	zonaB.camion_2.mostrar();
	cout << endl;
	cout << "-------------------" << endl;
	cout << "|    Cola Zona B     |" << endl;;
	cout << "-------------------" << endl;
	cout << endl;
	zonaB.cola.mostrar_cola();
	cout << endl;

	cout << "-------------------" << endl;
	cout << "|     ZONA C      |" << endl;
	cout << "-------------------" << endl;
	cout << "Camion C - 1" << endl;
	cout << endl;
	zonaC.camion_1.mostrar();
	cout << "Camion C - 2" << endl;
	cout << endl;
	zonaC.camion_2.mostrar();
	cout << endl;
	cout << "-------------------" << endl;
	cout << "|    Cola Zona C     |" << endl;;
	cout << "-------------------" << endl;
	cout << endl;
	zonaC.cola.mostrar_cola();
}
void Gestor::borrar_datos_Pilas()
{
	zonaA.camion_1.limpiarPila();
	zonaA.camion_2.limpiarPila();
	zonaB.camion_1.limpiarPila();
	zonaB.camion_2.limpiarPila();
	zonaC.camion_1.limpiarPila();
	zonaC.camion_2.limpiarPila();

	cout << "Se han eliminado los datos de los camiones." << endl;
}
void Gestor::borrar_datos_cola_zona()
{
	zonaA.cola.borrar_cola();
	zonaB.cola.borrar_cola();
	zonaC.cola.borrar_cola();
}
void Gestor::LimpiarCamiones(int concesinarios) { //limpiamos los camiones de los vehiculos restantes
	//zona A
	zonaA.limpiarCamion1(concesinarios);
	zonaA.limpiarCamion2(concesinarios);
	//zona B
	zonaB.limpiarCamion1(concesinarios);
	zonaB.limpiarCamion2(concesinarios);
	//zona C
	zonaC.limpiarCamion1(concesinarios);
	zonaC.limpiarCamion2(concesinarios);
}
void Gestor::SimulacionCompleta(int Nvehiculos, int NsacarVehiculos, int tamanoCamion, int concesinarios)
{
	borrar_cola_fabrica();
	borrar_datos_Pilas();
	borrar_datos_cola_zona();
	cout << endl;
	cout << "PASO 1: Creacion de vehiculos " << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
	//limpiamos los contenedores de datos para comenzar la simulación
	//PASO 1: Creacion de vehiculos
	crear_Vehiculos(Nvehiculos);
	mostrar_cola_fabrica();
	mostrar_cola_zonas_Y_pilas();
	//PASO 2: Vaciar la cola fabrica y cargarlos en los camiones
	cout << endl;
	cout << "PASO 2: Vaciar la cola fabrica y cargarlos en los camiones " << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
	while (cola_fabrica.getLongitud() != 0)
	{
		cout << endl;
		cargar_Vehiculos(NsacarVehiculos, tamanoCamion, concesinarios);
		mostrar_cola_fabrica();
		mostrar_cola_zonas_Y_pilas();
		cout << endl;
	}
	//PASO 3: Vaciar los camiones y insertarlos en las colas de las zonas
	cout << endl;
	cout << "PASO 3: Vaciar los camiones y insertarlos en la zona_cola " << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
	//metodo para limpiar los vehiculos restantes
	LimpiarCamiones(concesinarios);

	mostrar_cola_fabrica();
	mostrar_cola_zonas_Y_pilas();
	cout << endl;
}