#include "Lista.h"
Lista::Lista()
{
	raiz = NULL;
	longitud = 0;
}

Lista::~Lista()
{
	pnodoLista aux = raiz;
	pnodoLista bor;
	while (aux != NULL)
	{
		bor = aux;
		aux = aux->siguiente;
		delete bor;
	}
}

void Lista::mostrar()
{
	if (es_vacia()) {
		cout << "Se encuentra vacia la lista de pedidos." << endl;
	}
	else {

		pnodoLista aux = raiz;
		while (aux != NULL)
		{
			cout << " ------------------------------------- " << endl;
			cout << "Modelo del Pedido: " << aux->valor.get_modelo() << endl;
			cout << "Color del pedido: " << aux->valor.get_color() << endl;
			cout << "Zona del pedido: " << aux->valor.get_zona() << endl;
			cout << "Tipo del pedido: " << aux->valor.get_tipo() << endl;
			cout << "Concesionario del pedido: " << aux->valor.get_concesionario() << endl;
			cout << " ------------------------------------- " << endl;
			aux = aux->siguiente;
		}
		cout << endl;
	}
}

int Lista::getLongitud() {

	return this->longitud;
}


bool Lista::es_vacia()
{
	return (raiz == NULL) && (longitud == 0);
}

void Lista::vaciar_lista()
{
	if (es_vacia())
	{
		cout << "La lista de pedidos esta Vacia." << endl;
	}
	else {
		if (!es_vacia()) { Borrar(); }
	}
	cout << "La lista de pedidos ha sido vaciada con exito." << endl;
}

void Lista::insertar(Pedido p)
{
	pnodoLista nuevo;
	nuevo = new NodoLista(p);

	nuevo->valor = p;
	if (raiz == NULL)
	{
		raiz = nuevo;
	}
	else
	{
		if (p.get_tipo() > raiz->valor.get_tipo())
		{
			nuevo->siguiente = raiz;
			raiz = nuevo;
		}
		else
		{
			pnodoLista reco = raiz;
			pnodoLista atras = raiz;
			while (p.get_tipo() <= reco->valor.get_tipo() && reco->siguiente != NULL)
			{
				atras = reco;
				reco = reco->siguiente;
			}
			if (p.get_tipo() <= reco->valor.get_tipo())
			{
				reco->siguiente = nuevo;
			}
			else
			{
				nuevo->siguiente = reco;
				atras->siguiente = nuevo;
			}
		}
	}
	longitud++;
}

Pedido Lista::extraer()

{
	pnodoLista nodo;
	Pedido p;
	nodo = raiz;
	raiz = nodo->siguiente;
	p = nodo->valor;
	longitud--;
	delete nodo;
	return p;

}

void Lista::Borrar()

{
	while (!es_vacia()) {
		pnodoLista nodo;
		if (getLongitud() > 1) {
			nodo = raiz;
			raiz = nodo->siguiente;
			longitud--;
			delete nodo;
		}
		else {
			nodo = raiz;
			nodo->siguiente = NULL;
			raiz = nodo->siguiente;
			longitud--;
			delete nodo;
		}
	}

}
void Lista::eliminarPrimero() {
	if (!es_vacia())
	{
		NodoLista* aux = raiz;
		if (longitud == 1)
		{
			raiz = NULL;
			delete aux;
			longitud--;
		}
		else
		{
			raiz = raiz->siguiente;
			aux->siguiente = NULL;
			delete aux;
			longitud--;
		}
	}
}
Pedido Lista::buscarElementoLista(Vehiculo v)
{
	pnodoLista q = raiz;
	pnodoLista maximo = raiz;
	Pedido pedido;
	bool encontrado = false;
	if (q != NULL)
	{
		while (q->siguiente != NULL && encontrado != true)
		{
			if (q->valor.get_color() == v.get_color() && q->valor.get_modelo() == v.get_modelo())
			{
				maximo = q;
				pedido = maximo->valor;
				encontrado = true;
			}
			if (!encontrado) { q = q->siguiente; }
		}//cierre de while
		if (getLongitud() == 1) {
			if (q->valor.get_color() == v.get_color() && q->valor.get_modelo() == v.get_modelo())
			{
				maximo = q;
				pedido = maximo->valor;
				encontrado = true;
			}
		}
		if (encontrado) {
			if (getLongitud() > 1) {
				q = raiz;
				raiz = q->siguiente;
				longitud--;
				delete q;
			}
			else {
				q = raiz;
				q->siguiente = NULL;
				raiz = q->siguiente;
				longitud--;
				delete q;
			}
		}
	}
	if (getLongitud() == 0) {
		cout << "La lista de pedidos se quedo vacia." << endl;
	}
	return pedido;
}

bool Lista::encontrarElementoLista(Vehiculo v)
{
	pnodoLista q = raiz;
	bool encontrado = false;
	if (q != NULL)
	{
		while (q->siguiente != NULL && encontrado != true)
		{
			if (q->valor.get_color() == v.get_color() && q->valor.get_modelo() == v.get_modelo())
			{
				encontrado = true;
				cout << "Fue solicitado el vehiculo con bastidor: " << v.get_numeroBastidor() << endl;
			}
			q = q->siguiente;
		}
		if (getLongitud() == 1) {
			if (q->valor.get_color() == v.get_color() && q->valor.get_modelo() == v.get_modelo())
			{
				encontrado = true;
				cout << "Fue solicitado el vehiculo con bastidor: " << v.get_numeroBastidor() << endl;
			}
		}

	}
	return encontrado;
}
void Lista::cambioPrioridad() {
	pnodoLista q = raiz;
	int contador = 0;
	if (q != NULL)
	{
		while (contador != getLongitud())
		{
			if (q->valor.get_tipo() == "Normal")
			{
				q->valor.set_tipo("Prioritario");
			}
			q = q->siguiente;
			contador++;
		}

	}
}