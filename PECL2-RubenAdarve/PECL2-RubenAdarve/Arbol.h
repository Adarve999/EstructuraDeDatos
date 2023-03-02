#pragma once
#ifndef ARBOL_HPP
#define ARBOL_HPP
#include "NodoArbol.h"
#include <vector>
using namespace std;

class Arbol
{
public:
	Arbol();
	void insertar(Vehiculo val);
	void inorden();
	void inordenConces(string);
	void inordenBastidor(string);
	int altura();
	pnodoAbb getraiz();
	~Arbol();
	int ComprobacionConcesionario(string conces);
private:
	pnodoAbb raiz;
	pnodoAbb insertar(pnodoAbb, Vehiculo);
	int altura(pnodoAbb);

	void inorden(pnodoAbb);
	void inordenConces(pnodoAbb, string);
	void inordenBastidor(pnodoAbb, string);

};
#endif //ARBOL_HPP