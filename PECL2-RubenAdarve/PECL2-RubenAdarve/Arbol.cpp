#include "Arbol.h"
#include <iostream>
using namespace std;
Arbol::Arbol() {
	Vehiculo p;
	p.set_numeroBastidor("000AAAA");
	p.set_concesionario("C0");
	p.generarZona();//GENERAMOS LA ZONA RANDOM
	raiz = new NodoArbol(p);
}
int Arbol::altura() {
	return altura(raiz);
}
int Arbol::altura(pnodoAbb arbol)
{
	if (arbol == NULL) {
		return 0;
	}
	else {
		return 1 + max(altura(arbol->izq), altura(arbol->der));
	}
}
void Arbol::inorden() {
	inorden(raiz);
}
void Arbol::inorden(pnodoAbb arbol) {
	if (arbol != NULL)
	{
		inorden(arbol->izq);
		arbol->dato.mostrar_Vehiculo();
		inorden(arbol->der);
	}
}
void Arbol::inordenConces(string conces) {
	inordenConces(raiz, conces);
}
//Solo imprime el arbol
void Arbol::inordenConces(pnodoAbb arbol, string conces) {
	if (arbol != NULL)
	{
		inordenConces(arbol->izq, conces);
		if (arbol->dato.get_concesionario() == conces) {
			//solo muestre el arbol con los que se cumple esa condición
			arbol->dato.mostrar_Vehiculo();
		}
		inordenConces(arbol->der, conces);
	}
}
void Arbol::inordenBastidor(string conces) {
	inordenBastidor(raiz, conces);
}
//Solo imprime el arbol
void Arbol::inordenBastidor(pnodoAbb arbol, string bastidor) {
	if (arbol != NULL)
	{
		inordenBastidor(arbol->izq, bastidor);
		if (arbol->dato.get_numeroBastidor() == bastidor) {
			//solo muestre el arbol con los que se cumple esa condición
			arbol->dato.mostrar_Vehiculo();
		}
		inordenBastidor(arbol->der, bastidor);
	}
}
void Arbol::insertar(Vehiculo p) {
	raiz = insertar(raiz, p);
}
pnodoAbb Arbol::insertar(pnodoAbb arbol, Vehiculo p) {
	if (arbol == NULL) {
		arbol = new NodoArbol(p);
	}
	//estamos cogiendo el numero del concesionario con el split
	else if (ComprobacionConcesionario(p.get_concesionario()) <= ComprobacionConcesionario(arbol->dato.get_concesionario())) {
		arbol->izq = insertar(arbol->izq, p);
	}
	else if (ComprobacionConcesionario(p.get_concesionario()) > ComprobacionConcesionario(arbol->dato.get_concesionario())) {
		arbol->der = insertar(arbol->der, p);
	}
	return arbol;

}
int Arbol::ComprobacionConcesionario(string conces) {
	//con esto sacamos el numero del concesinario //CX // siendo X el numero a sacar
	return stoi(conces.substr(1, conces.length() - 1));
}
pnodoAbb Arbol::getraiz() {
	return raiz;
}

Arbol::~Arbol()
{

}
