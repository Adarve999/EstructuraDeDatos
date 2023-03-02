#include <string>
#include "Vehiculo.h"
#include "Gestor.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <random>
using namespace std;

int main()
{	
	system("title PECL2 -Ruben Adarve");
	system("color 1F");//poner el color de la consola en azul
	srand(time(NULL));
	int Nvehiculos, NsacarVehiculos, tamanoCamion, Nconcesionarios;

	Nvehiculos = 2;//predefinido los coches que se generan
	NsacarVehiculos = 3;//predefinido los coches que se van a sacar de la cola_fabrica
	tamanoCamion = 3;//tamaño las pilas camion
	Nconcesionarios = 20;//numero de generación de pedidos

	Gestor gestor;
	char respuesta;
	cout << "	A: Generar aleatoriamente la cola de automoviles disponibles en la fabrica con NV automoviles. \n";
	cout << "	B: Generar aleatoriamente la cola de automoviles disponibles en la fabrica solicitando NV por pantalla.\n";
	cout << "	C: Mostrar en pantalla los datos de la cola de automoviles disponibles en la fabrica.\n";
	cout << "	D: Borrar la cola de automoviles disponibles en la fabrica. \n";
	cout << "	E: Generar aleatoriamente al menos NC*2 pedidos de los concesionarios e insertarlos en la lista de pedidos.\n";
	cout << "	F: Leer de teclado los datos de tantos pedidos como desee el usuario,\n"
		"	    e insertarlos en la lista de pedidos.\n";
	cout << "	G: Mostrar en pantalla los datos de la lista de pedidos.\n";
	cout << "	H: Borrar la lista de pedidos. \n";
	cout << "	I: Avanzar un paso en la simulacion: salen NS automoviles de la cola de fabrica y \n"
		"	llegan a una de las naves de reparto(buscando una solicitud en la lista de pedidos). \n";
	cout << "	J: Avanzar un paso en la simulacion solicitando NS por pantalla: salen NS automoviles de la cola de fabrica  \n"
		"	    y llegan a una de las naves de reparto (buscando una solicitud en la lista de pedidos).\n";
	cout << "	K: Mostrar en pantalla los datos de las naves de reparto (camiones o pilas y registro o cola de zona de cada una de ellas). \n";
	cout << "	L: Realizar la simulacion hasta finalizar los automoviles disponibles (en cada paso salen NS automoviles)\n"
		"	En cada uno de los pasos se mostrarán en pantalla los datos de la cola de fabrica y de las naves de reparto. \n";
	cout << "	M: Almacenar en el arbol binario un automovil cuyos datos son leidos de teclado. \n";
	cout << "	N: Almacenar en el arbol binario los datos de los automoviles de una de las colas de zona. \n";
	cout << "	P: Almacenar en el arbol binario los datos de los automoviles de todas las colas de zona. \n";
	cout << "	Q: Visualizar los datos de todos los automoviles entregados ordenados por numero de concesionario. \n";
	cout << "	R: Visualizar los automoviles entregados en un concesionario cuyo numero es leido de teclado. \n";
	cout << "	S: Visualizar el concesionario y zona en que se ha entregado un automovil, leyendo de teclado su numero de bastidor. \n";
	cout << "	Z: Menu. \n";
	cout << "	0: Salir. \n";
	cout << endl;
	do
	{
		cin >> respuesta;
		string NV;
		string NS;
		string zonaArbol;
		string concesionarioArbol;
		string bastidorArbol;
		switch (respuesta) {
		case('A'):
			gestor.crear_Vehiculos(Nvehiculos);
			break;
		case('B'):
			gestor.crear_Vehiculos(Nvehiculos);
			break;
		case('C'):
			gestor.mostrar_cola_fabrica();
			break;
		case('D'):
			gestor.borrar_cola_fabrica();
			break;
		case('E'):
			gestor.generarPedidos(Nconcesionarios);
			break;
		case('F'):
			gestor.generarPedidosUsuario();
			break;
		case('G'):
			gestor.mostrarListaPedidos();
			break;
		case('H'):
			gestor.vaciarListaPedidos();
			break;
		case('I'):
			gestor.cargar_Vehiculos(NsacarVehiculos, tamanoCamion);
			break;
		case('J'):
			cout << "Introduzca el numero de vehiculos para cagar en camiones." << endl;
			cin >> NS;
			gestor.cargar_VehiculosPorUsuario(NS, tamanoCamion);
			break;
		case('K'):
			gestor.mostrar_cola_zonas_Y_pilas();
			break;
		case('L'):
			gestor.SimulacionCompleta(Nvehiculos, NsacarVehiculos, tamanoCamion, Nconcesionarios);
			//Nconcesionarios es Npedidos
			break;
		case('M'):
			gestor.InsercionVehiculoEnArbol();
			break;
		case('N'):
			cout << "Introduzca la zona que quieres mover al arbol (A,B,C)." << endl;
			cin >> zonaArbol;
			gestor.rellenar_ArbolCliente(zonaArbol);
			break;
		case('P'):
			gestor.rellenar_arbol();
			break;
		case('Q'):
			gestor.ordenArbol();
			break;
		case('R'):
			cout << "Introduzca el concesionario que quiere ver." << endl;
			cin >> concesionarioArbol;
			gestor.visualizarArbolSegunConces(concesionarioArbol);
			break;
		case('S'):
			cout << "Introduzca el bastidor del vehiculo." << endl;
			cin >> bastidorArbol;
			gestor.visualizarArbolSegunBastidor(bastidorArbol);
			break;
		case('Z'):
			cout << "	A: Generar aleatoriamente la cola de automoviles disponibles en la fabrica con NV automoviles. \n";
			cout << "	B: Generar aleatoriamente la cola de automoviles disponibles en la fabrica solicitando NV por pantalla.\n";
			cout << "	C: Mostrar en pantalla los datos de la cola de automoviles disponibles en la fabrica.\n";
			cout << "	D: Borrar la cola de automoviles disponibles en la fabrica. \n";
			cout << "	E: Generar aleatoriamente al menos NC*2 pedidos de los concesionarios e insertarlos en la lista de pedidos.\n";
			cout << "	F: Leer de teclado los datos de tantos pedidos como desee el usuario,\n"
				"	    e insertarlos en la lista de pedidos.\n";
			cout << "	G: Mostrar en pantalla los datos de la lista de pedidos.\n";
			cout << "	H: Borrar la lista de pedidos. \n";
			cout << "	I: Avanzar un paso en la simulacion: salen NS automoviles de la cola de fabrica y \n"
				"	llegan a una de las naves de reparto(buscando una solicitud en la lista de pedidos). \n";
			cout << "	J: Avanzar un paso en la simulacion solicitando NS por pantalla: salen NS automoviles de la cola de fabrica  \n"
				"	    y llegan a una de las naves de reparto (buscando una solicitud en la lista de pedidos).\n";
			cout << "	K: Mostrar en pantalla los datos de las naves de reparto (camiones o pilas y registro o cola de zona de cada una de ellas). \n";
			cout << "	L: Realizar la simulacion hasta finalizar los automoviles disponibles (en cada paso salen NS automoviles)\n"
				"	En cada uno de los pasos se mostrarán en pantalla los datos de la cola de fabrica y de las naves de reparto. \n";
			cout << "	M: Almacenar en el arbol binario un automovil cuyos datos son leidos de teclado. \n";
			cout << "	N: Almacenar en el arbol binario los datos de los automoviles de una de las colas de zona. \n";
			cout << "	P: Almacenar en el arbol binario los datos de los automoviles de todas las colas de zona. \n";
			cout << "	Q: Visualizar los datos de todos los automoviles entregados ordenados por numero de concesionario. \n";
			cout << "	R: Visualizar los automoviles entregados en un concesionario cuyo numero es leido de teclado. \n";
			cout << "	S: Visualizar el concesionario y zona en que se ha entregado un automovil, leyendo de teclado su numero de bastidor. \n";
			cout << "	Z: Menu. \n";
			cout << "	0: Salir. \n";
			cout << endl;
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
