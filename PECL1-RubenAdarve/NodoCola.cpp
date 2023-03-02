#include "NodoCola.h"

NodoCola::NodoCola(Vehiculo p, NodoCola* sig) {
	valor = p;
	siguiente = sig;
}
NodoCola::~NodoCola()
{
}