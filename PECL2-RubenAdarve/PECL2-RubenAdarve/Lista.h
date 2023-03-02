#include <iostream>
#include "NodoLista.h"
#include "Vehiculo.h"
using namespace std;

class Lista {
private:
	NodoLista* raiz;
	int longitud;
public:
	Lista();
	~Lista();
	void mostrar();
	int getLongitud();
	bool es_vacia();
	void vaciar_lista();
	void insertar(Pedido p);
	Pedido extraer();
	Pedido buscarElementoLista(Vehiculo v);
	void Borrar();
	bool encontrarElementoLista(Vehiculo v);
	void eliminarPrimero();
	void cambioPrioridad();
};

