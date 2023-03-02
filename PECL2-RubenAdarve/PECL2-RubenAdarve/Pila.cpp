#include "Pila.h"
#include "Cola.h"
#include "Vehiculo.h"
#include "Gestor.h"
Pila::Pila()
{
	ultimo = NULL;
	longitud = 0;
	lleno = false;
}

void Pila::insertar(Vehiculo p)
{
	pnodoPila nuevo;
	nuevo = new NodoPila(p, ultimo);
	ultimo = nuevo;
	longitud++;
}

Vehiculo Pila::extraer()
{
	pnodoPila nodo;
	Vehiculo p;
	if (!ultimo)
		return Vehiculo();
	nodo = ultimo;
	ultimo = nodo->siguiente;
	p = nodo->valor;
	longitud--;
	delete nodo;
	return p;

}

Vehiculo Pila::cima()
{
	pnodoPila nodo;
	if (!ultimo)
		return Vehiculo();
	return ultimo->valor;

}

void Pila::mostrar()
{
	pnodoPila aux = ultimo;
	while (aux) {
		cout << "numero de bastidor --> " << aux->valor.get_numeroBastidor() << endl;
		cout << "Modelo del coche --> " << aux->valor.get_modelo() << endl;
		cout << "Color del coche --> " << aux->valor.get_color() << endl;
		cout << "Concesionario --> " << aux->valor.get_concesionario() << endl;
		cout << "Zona --> " << aux->valor.get_zona() << endl;
		cout << " ------------------------------------- " << endl;
		aux = aux->siguiente;
	}
	cout << endl;
}

int Pila::getLongitud()
{
	return this->longitud;
}
bool Pila::getLleno()
{
	return this->lleno;
}

void Pila::setLleno(bool lleno) {
	this->lleno = lleno;
}

void Pila::limpiarPila()
{
	while (getLongitud() != 0)
	{
		extraer();
	}
}

Pila::~Pila()
{
	pnodoPila aux;
	while (ultimo) {
		aux = ultimo;
		ultimo = ultimo->siguiente;
		delete aux;
	}

}
