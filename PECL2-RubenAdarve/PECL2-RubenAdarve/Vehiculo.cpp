#include "Vehiculo.h"
#include <time.h>
#include <random>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
Vehiculo::Vehiculo() {
	generarBastidor();
	generarModelo();
	generarColor();
	this->concesionario = "";
	this->zona = "";
}
void Vehiculo::generarBastidor()
{
	int selectorDigitos, selectorLetras;
	string bastidor;
	string digitos[10] = { "0","1","2","3","4","5","6","7","8","9" };
	string letras[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	for (int i = 0; i < 3; i++)
	{
		selectorDigitos = rand() % 10;
		bastidor += digitos[selectorDigitos];
	}
	for (int i = 0; i < 4; i++)
	{
		selectorLetras = rand() % 26;
		bastidor += letras[selectorLetras];
	}
	this->numeroBastidor = bastidor;
}

void Vehiculo::generarModelo()
{
	int selectorModelo;
	string modelos[4] = { "M1", "M2", "M3", "M4" };
	selectorModelo = rand() % 4;
	this->modelo = modelos[selectorModelo];
}

void Vehiculo::generarZona()
{
	int selectorModelo;
	string modelos[3] = { "A", "B", "C" };
	selectorModelo = rand() % 3;
	this->zona = modelos[selectorModelo];
}

void Vehiculo::generarColor()
{
	int selectorColor;
	string colores[3] = { "C1", "C2","C3"};
	selectorColor = rand() % 3;
	this->color = colores[selectorColor];
}

void Vehiculo::mostrar_Vehiculo() {
	cout << "El numero de bastidor: " << numeroBastidor << endl;
	cout << "El color es:  " << color << endl;
	cout << "El modelo es:  " << modelo << endl;
	cout << "El concesionario es: " << concesionario << endl;
	cout << "zona asignada : " << zona << endl;
	cout << " ------------------------------------- " << endl;
}
//Getters
string Vehiculo::get_numeroBastidor() {
	return this->numeroBastidor;
}
string Vehiculo::get_modelo() {
	return this->modelo;
}
string Vehiculo::get_color() {
	return this->color;
}
string Vehiculo::get_concesionario() {
	return this->concesionario;
}
string Vehiculo::get_zona() {
	return this->zona;
}

//Setters
void Vehiculo::set_numeroBastidor(string numero) {
	this->numeroBastidor = numero;
}
void Vehiculo::set_modelo(string modelo) {
	this->modelo = modelo;
}
void Vehiculo::set_color(string color) {
	this->color = color;
}
void Vehiculo::set_concesionario(string concesionario) {
	this->concesionario = concesionario;
}
void Vehiculo::set_zona(string zona) {
	this->zona = zona;
}
