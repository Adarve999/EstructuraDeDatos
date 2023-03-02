#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Pedido
{
private:
	string modelo;
	string color;
	string concesionario;
	string zona;
	string tipo;

	void generarModelo();
	void generarColor();
	void generarZona();
	void generarTipo();
	void generarConcesionario();

public:
	Pedido();
	~Pedido() {
	};
	void mostrar_Pedido();	
	string get_modelo();
	string get_color();
	string get_concesionario();
	string get_zona();
	string get_tipo();

	void set_modelo(string modelo);
	void set_color(string color);
	void set_concesionario(string concesionario);
	void set_zona(string zona);
	void set_tipo(string tipo);
};

