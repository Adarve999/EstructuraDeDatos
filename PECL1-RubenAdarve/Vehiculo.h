#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Vehiculo
{
private:
	string numeroBastidor;
	string modelo;
	string color;
	string concesionario;
	void generarBastidor();
	void generarModelo();
	void generarColor();

public:
	Vehiculo();
	~Vehiculo() {
	}; 
	void mostrar_Vehiculo();//muestra los datos del vehiculo	
	string generarConcesionario(int i);

	string get_numeroBastidor();
	string get_modelo();
	string get_color();
	string get_concesionario();

	void set_numeroBastidor(string numero);
	void set_modelo(string modelo);
	void set_color(string color);
	void set_concesionario(string concesionario);
};

