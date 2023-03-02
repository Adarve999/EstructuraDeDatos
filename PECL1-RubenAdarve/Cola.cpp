#include "Pila.h"
#include "Vehiculo.h"
#include "Cola.h"
Cola::Cola() {

	primero = NULL;
	ultimo = NULL;
	longitud = 0;

}

void Cola::insertar(Vehiculo p) {
	pnodoCola nuevo;
	nuevo = new NodoCola(p);

	if (ultimo)
		ultimo->siguiente = nuevo;
	ultimo = nuevo;

	if (!primero)
		primero = nuevo;
	longitud++;

}

void Cola::mostrar() {
	pnodoCola  aux = primero;

	while (aux) {
		cout << "Numero de bastidor --> " << aux->valor.get_numeroBastidor() << endl;
		cout << "Modelo del coche --> " << aux->valor.get_modelo() << endl;
		cout << "Color del coche --> " << aux->valor.get_color() << endl;
		cout << "Concesionario --> " << aux->valor.get_concesionario() << endl;
		cout << " ------------------------------------- " << endl;
		aux = aux->siguiente;
	}
	cout << endl;
}

Vehiculo Cola::eliminar()
{
	pnodoCola nodo;
	Vehiculo p;
	nodo = primero;
	if (!nodo) {
		return Vehiculo();
	}
	primero = nodo->siguiente;
	p = nodo->valor;
	delete nodo;

	if (!primero)
		ultimo = NULL;
	longitud--;
	return p;
}

Vehiculo Cola::verPrimero() {
	return primero->valor;
}
int Cola::getLongitud()
{
	return this->longitud;
}
Cola::~Cola()
{
	while (primero)
		eliminar();
}

void Cola::mostrar_cola() {
	if (getLongitud() == 0)
	{
		cout << "La cola de la zona esta vacia de coches." << endl;
	}
	else
	{
		mostrar();
	}

}
void Cola::borrar_cola() {
	if (getLongitud() == 0)
	{
		cout << "La cola esta vacia." << endl;
	}
	else
	{
		while (getLongitud() != 0)
		{
			eliminar();
		}
		cout << "Se ha eliminado la cola correctamente." << endl;

	}
}