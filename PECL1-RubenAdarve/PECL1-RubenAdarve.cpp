#include <string>
#include "Vehiculo.h"
#include "Gestor.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <random>
using namespace std;

int main()
{
	srand(time(NULL));
	int Nvehiculos, NsacarVehiculos, tamanoCamion,Nconcesionarios;

	Nvehiculos = 27;//predefinido los coches que se generan
	NsacarVehiculos = 8;//predefinido los coches que se van a sacar de la cola_fabrica
	tamanoCamion = 7;//tamaño las pilas camion
	Nconcesionarios = 4;

	Gestor gestor;
	char respuesta;
	cout << "	A: Generar aleatoriamente la cola de automoviles disponibles en la fabrica con NV automoviles. \n";
	cout << "	B: Generar aleatoriamente la cola de automoviles disponibles en la fabrica solicitando NV por pantalla.\n";
	cout << "	C: Mostrar en pantalla los datos de la cola de automoviles disponibles en la fabrica.\n";
	cout << "	D: Borrar la cola de automoviles disponibles en la fabrica. \n";
	cout << "	E: Avanzar un paso en la simulacion, segun se ha descrito anteriormente, utilizando NS automoviles.\n";
	cout << "	F: Avanzar un paso en la simulacion, según se ha descrito anteriormente,\n"
		"	   solicitando el numero de automoviles NS por pantalla.\n";
	cout << "	G: Mostrar en pantalla los datos de los almacenes de zona (camiones o pilas) y registro o cola_zona).\n";
	cout << "	H: Borrar los datos de los almacenes de zona (camiones o pilas). \n";
	cout << "	I: Borrar los datos de los registros de zona (cola_zona). \n";
	cout << "	J: Realizar la simulacion hasta finalizar los automoviles disponibles (en cada paso salen NS automoviles). \n"
		"	   En cada uno de los pasos se mostraran en pantalla los datos de la cola de fabrica y de cada una de las zonas de reparto (pilas y cola). \n";
	cout << "	0: Salir. \n";
	cout << endl;
	do
	{
		cin >> respuesta;
		string NV;
		string NS;
		switch (respuesta) {
		case('A'):
			gestor.crear_Vehiculos(Nvehiculos);
			break;
		case('B'):
			cout << "Introduzca el numero de vehiculos a generar." << endl;
			cin >> NV;
			gestor.crear_VehiculosPorUsuario(NV);
			break;
		case('C'):
			gestor.mostrar_cola_fabrica();
			break;
		case('D'):
			gestor.borrar_cola_fabrica();
			break;
		case('E'):
			gestor.cargar_Vehiculos(NsacarVehiculos, tamanoCamion,Nconcesionarios);
			break;
		case('F'):
			cout << "Introduzca el numero de vehiculos para cagar en camiones." << endl;
			cin >> NS;
			gestor.cargar_VehiculosPorUsuario(NS, tamanoCamion, Nconcesionarios);
			break;
		case('G'):
			gestor.mostrar_cola_zonas_Y_pilas();
			break;
		case('H'):
			gestor.borrar_datos_Pilas();
			break;
		case('I'):
			gestor.borrar_datos_cola_zona();
			break;
		case('J'):
			gestor.SimulacionCompleta(Nvehiculos, NsacarVehiculos, tamanoCamion,Nconcesionarios);
			break;
		default:
			if (respuesta == '0')
			{
				cout << "Programa abandonado con exito" << endl;
			}
			else
			{
				cout << "Respuesta incorrecta \n";
			}
			break;
		}
	} while (respuesta != '0');
	return 0;
}
