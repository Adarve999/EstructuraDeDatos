#include "NodoPila.h"

NodoPila::NodoPila(Vehiculo p, NodoPila* sig)
{
	valor = p;
	siguiente = sig;
}
NodoPila::~NodoPila()
{
}
