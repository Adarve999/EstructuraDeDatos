#include "Pedido.h"

class NodoLista {


public:
    NodoLista(Pedido p, NodoLista* sig = NULL);
    ~NodoLista();
private:
    Pedido valor;
    NodoLista* siguiente;
    friend class Lista;
};
typedef NodoLista* pnodoLista;