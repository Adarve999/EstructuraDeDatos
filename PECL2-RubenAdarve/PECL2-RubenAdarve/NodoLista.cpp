#include "NodoLista.h"
NodoLista::NodoLista(Pedido p, NodoLista* sig)

{
	valor = p;
	siguiente = sig;
}
NodoLista::~NodoLista()

{
}