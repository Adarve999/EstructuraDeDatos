#include "Gestor.h"
#include "Vehiculo.h"
#include "Zona.h"
#include "Pedido.h"
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
	int Nmodelos = 0;
	while (Nmodelos != 4) {
		if (Nmodelos == 0) {
			for (int x = 0; x <= 2; x++) {
				Vehiculo v;
				v.set_modelo("M1");
				for (int y = 0; y <= 1; y++) {
					v.generarBastidor();
					if (x == 0) {
						v.set_color("C1");
					}
					else if (x == 1) {
						v.set_color("C2");
					}
					else if (x == 2) {
						v.set_color("C3");
					}
					cola_fabrica.insertar(v);
				}
			}
		}
		else if (Nmodelos == 1) {
			for (int x = 0; x <= 2; x++) {
				Vehiculo v;
				v.set_modelo("M2");
				for (int y = 0; y <= 1; y++) {
					v.generarBastidor();
					if (x == 0) {
						v.set_color("C1");
					}
					else if (x == 1) {
						v.set_color("C2");
					}
					else if (x == 2) {
						v.set_color("C3");
					}
					cola_fabrica.insertar(v);
				}
			}
		}
		else if (Nmodelos == 2) {
			for (int x = 0; x <= 2; x++) {
				Vehiculo v;
				v.set_modelo("M3");
				for (int y = 0; y <= 1; y++) {
					v.generarBastidor();
					if (x == 0) {
						v.set_color("C1");
					}
					else if (x == 1) {
						v.set_color("C2");
					}
					else if (x == 2) {
						v.set_color("C3");
					}
					cola_fabrica.insertar(v);
				}
			}
		}
		else if (Nmodelos == 3) {
			for (int x = 0; x <= 2; x++) {
				Vehiculo v;
				v.set_modelo("M4");
				for (int y = 0; y <= 1; y++) {
					v.generarBastidor();
					if (x == 0) {
						v.set_color("C1");
					}
					else if (x == 1) {
						v.set_color("C2");
					}
					else if (x == 2) {
						v.set_color("C3");
					}
					cola_fabrica.insertar(v);
				}
			}
		}
		Nmodelos++;
	}
	cout << "Generados - coches." << endl;
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
	//cambiamos la prioridad de los pedidos si se vacia la cola fabrica
	listaPedidos.cambioPrioridad();

}

void Gestor::cargar_Vehiculos(int NS, int tamanoCamion)
{
	if (cola_fabrica.getLongitud() == 0)
	{
		cout << "La cola de la fabrica esta vacia de coches." << endl;
	}
	else
	{
		if (cola_fabrica.getLongitud() <= NS) { NS = cola_fabrica.getLongitud(); } //para que no crees de más vehiculos
		cargaPilas(NS, tamanoCamion); // metodo para llenar las pilas
	}
}
void Gestor::cargar_VehiculosPorUsuario(string cadUsuario, int tamanoCamion)
{

	if (cola_fabrica.getLongitud() == 0)
	{
		cout << "La cola de la fabrica esta vacia de coches." << endl;
	}
	else
	{
		int nVehiculos = stoi(cadUsuario);//casteo de string a int
		if (cola_fabrica.getLongitud() <= nVehiculos) { nVehiculos = cola_fabrica.getLongitud(); }//para que no crees de más vehiculos
		cargaPilas(nVehiculos, tamanoCamion);  // metodo para llenar las pilas
	}
}
void Gestor::cargaPilas(int Vehiculos, int tamanoCamion) {
	int x = 0;//Contador para saber cuanto vehiculos están en la lista de pedidos
	cout << endl;
	cout << "vehiculos sacados de la cola Fabrica: " << Vehiculos << endl;
	cout << endl;
	for (int i = 0; i < Vehiculos; i++)
	{
		//entras en el for puedes pedir que saquen X vehiculos pero
		//no alomejor no estan en la lista de pedidos y desechas esos vehiculos
		Vehiculo v = cola_fabrica.eliminar();
		if (listaPedidos.encontrarElementoLista(v)) {
			//este if sirve para saber si está o no en la lista de pedidos
			Pedido p = listaPedidos.buscarElementoLista(v);
			//miramos si lo encuentra o no

			if (p.get_zona() == "A") {
				v.set_zona(p.get_zona());//seteamos la zona al vehiculo
				v.set_concesionario(p.get_concesionario());//seteamos el concesionario al vehiculo
				zonaA.seleccionCamion(tamanoCamion, v);
			}

			else if (p.get_zona() == "B") {
				v.set_zona(p.get_zona());//seteamos la zona al vehiculo
				v.set_concesionario(p.get_concesionario());//seteamos el concesionario al vehiculo
				zonaB.seleccionCamion(tamanoCamion, v);
			}

			else if (p.get_zona() == "C") {
				v.set_zona(p.get_zona());//seteamos la zona al vehiculo
				v.set_concesionario(p.get_concesionario());//seteamos el concesionario al vehiculo
				zonaC.seleccionCamion(tamanoCamion, v);
			}
			x++;//contador para saber los pedidos que se realizaron con exito
		}
		else {
			cout << "El vehiculo con bastidor " << v.get_numeroBastidor() << " no esta en la lista de pedidos." << endl;
		}

		zonaA.vaciarCamion1();
		zonaA.vaciarCamion2();

		zonaB.vaciarCamion1();
		zonaB.vaciarCamion2();

		zonaC.vaciarCamion1();
		zonaC.vaciarCamion2();

		if (cola_fabrica.getLongitud() == 0) {
			//cambiamos la prioridad de los pedidos si se vacia la cola fabrica
			listaPedidos.cambioPrioridad();
		}
	}

	cout << endl;
	cout << "Vehiculos cargados correctamente: " << x << endl;
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
void Gestor::LimpiarCamiones() { //limpiamos los camiones de los vehiculos restantes
	//zona A
	zonaA.limpiarCamion1();
	zonaA.limpiarCamion2();
	//zona B
	zonaB.limpiarCamion1();
	zonaB.limpiarCamion2();
	//zona C
	zonaC.limpiarCamion1();
	zonaC.limpiarCamion2();
}

void Gestor::vaciarListaPedidos() {
	listaPedidos.vaciar_lista();
}
void Gestor::mostrarListaPedidos() {
	cout << endl;
	cout << "---------------------------" << endl;
	cout << "|     lista de Pedidos     |" << endl;
	cout << "---------------------------" << endl;
	cout << endl;
	listaPedidos.mostrar();
}
void Gestor::generarPedidos(int i) {
	genPedidos(i);
}

void Gestor::generarPedidosUsuario() {
	Pedido p;
	string color, modelo, tipo, conces, zona;
	cout << "introduzca el modelo (1-4): " << endl;
	cin >> modelo;
	cout << "introduzca el color (1-2): " << endl;
	cin >> color;
	cout << "Introduzca el tipo (Normal/Prioritario): " << endl;
	cin >> tipo;
	cout << "Introduzca la zona (A,B,C): " << endl;
	cin >> zona;
	cout << "Introduzca el concesionario (1-15): " << endl;
	cin >> conces;
	p.set_modelo("M" + modelo);
	p.set_tipo(tipo);
	p.set_color("C" + color);
	p.set_concesionario("C" + conces);
	p.set_zona(zona);
	listaPedidos.insertar(p);
	cout << " ---------Pedido Insertado--------- " << endl;


}
void Gestor::genPedidos(int i) {
	for (int y = 0; y < i; y++) {
		Pedido p;
		listaPedidos.insertar(p);

	}
	cout << "Pedidos generados: " << i << endl;
}

void Gestor::rellenar_arbol() {//vacia todas las zonas y las mete en el arbol
	LimpiarCamiones();
	while (zonaA.cola.getLongitud() != 0)
	{
		Vehiculo p = zonaA.cola.eliminar();
		arbol.insertar(p);
	}
	cout << "Introducidos los vehiculos de la zona A en el arbol." << endl;
	while (zonaB.cola.getLongitud() != 0)
	{
		Vehiculo p = zonaB.cola.eliminar();
		arbol.insertar(p);
	}
	cout << "Introducidos los vehiculos de la zona B en el arbol." << endl;
	while (zonaC.cola.getLongitud() != 0) {

		Vehiculo p = zonaC.cola.eliminar();
		arbol.insertar(p);
	}
	cout << "Introducidos los vehiculos de la zona C en el arbol." << endl;
}
void Gestor::rellenar_ArbolCliente(string zona) {
	//vacia segun la zona que introduce el usuario y al inserta en el arbol.
	if (zona == "A") {
		while (zonaA.cola.getLongitud() != 0)
		{
			Vehiculo p = zonaA.cola.eliminar();
			arbol.insertar(p);
		}
		cout << "Introducidos los vehiculos de la zona A en el arbol." << endl;
	}
	else if (zona == "B") {
		while (zonaB.cola.getLongitud() != 0)
		{
			Vehiculo p = zonaB.cola.eliminar();
			arbol.insertar(p);
		}
		cout << "Introducidos los vehiculos de la zona B en el arbol." << endl;
	}
	else if (zona == "C") {
		while (zonaC.cola.getLongitud() != 0) {

			Vehiculo p = zonaC.cola.eliminar();
			arbol.insertar(p);
		}
		cout << "Introducidos los vehiculos de la zona C en el arbol." << endl;
	}
}
void Gestor::InsercionVehiculoEnArbol() {
	Vehiculo p;
	string Nbastidor, zona, modelo, color, concesionario;

	cout << "Introduzca numero de bastidor: " << endl;
	cin >> Nbastidor;
	cout << "Introduzca el color: " << endl;
	cin >> color;
	cout << "Introduzca el modelo: " << endl;
	cin >> modelo;
	cout << "Introduzca el concesionario: " << endl;
	cin >> concesionario;
	cout << "Introduzca la zona: " << endl;
	cin >> zona;
	p.set_numeroBastidor(Nbastidor);
	p.set_color(color);
	p.set_modelo(modelo);
	p.set_concesionario(concesionario);
	p.set_zona(zona);
	arbol.insertar(p);
	cout << " ---------Insertado con Exito--------- " << endl;

}
void Gestor::ordenArbol() {
	cout << endl;
	cout << "-------------------------" << endl;
	cout << "|     Arbol Binario      |" << endl;
	cout << "-------------------------" << endl;
	cout << endl;
	arbol.inorden();
}

void Gestor::visualizarArbolSegunConces(string conces) {
	cout << endl;
	cout << "-------------------------" << endl;
	cout << "|     Arbol Binario      |" << endl;
	cout << "-------------------------" << endl;
	cout << endl;
	arbol.inordenConces(conces);
}
void Gestor::visualizarArbolSegunBastidor(string conces) {
	cout << endl;
	cout << "-------------------------" << endl;
	cout << "|     Arbol Binario      |" << endl;
	cout << "-------------------------" << endl;
	cout << endl;
	arbol.inordenBastidor(conces);
}

void Gestor::SimulacionCompleta(int Nvehiculos, int NsacarVehiculos, int tamanoCamion, int Npedidos)
{
	borrar_cola_fabrica();
	borrar_datos_Pilas();
	borrar_datos_cola_zona();
	cout << endl;
	cout << "PASO 1: Creacion de vehiculos y pedidos " << endl;
	cout << "-----------------------------------------" << endl;
	cout << endl;
	//limpiamos los contenedores de datos para comenzar la simulación
	//PASO 1: Creacion de vehiculos
	crear_Vehiculos(Nvehiculos);//generas Nvehiculos
	generarPedidos(Npedidos);//generas Npedidos
	mostrar_cola_fabrica();
	mostrarListaPedidos();
	mostrar_cola_zonas_Y_pilas();

	//PASO 2: Vaciar la cola fabrica y cargarlos en los camiones
	cout << endl;
	cout << "PASO 2: Vaciar la cola fabrica y cargarlos en los camiones " << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
	while (cola_fabrica.getLongitud() != 0) //limpiamos la cola fabrica
	{
		cout << endl;
		cargar_Vehiculos(NsacarVehiculos, tamanoCamion);
		mostrar_cola_fabrica();
		mostrarListaPedidos();
		mostrar_cola_zonas_Y_pilas();

		cout << endl;
	}
	//PASO 3: Vaciar los camiones y insertarlos en las colas de las zonas
	cout << endl;
	cout << "PASO 3: Vaciar los camiones y insertarlos en la zona_cola " << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
	//metodo para limpiar los vehiculos restantes
	LimpiarCamiones();

	mostrar_cola_fabrica();
	mostrarListaPedidos();
	mostrar_cola_zonas_Y_pilas();

	cout << endl;

	cout << "PASO 4: Introduccion de vehiculos en arbol " << endl;
	cout << "-------------------------------------------" << endl;
	rellenar_arbol(); //limpiamos todas las colas de las zonas
	mostrar_cola_fabrica();
	mostrarListaPedidos();
	mostrar_cola_zonas_Y_pilas();
	ordenArbol();

}