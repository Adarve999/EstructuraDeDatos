#include "Pedido.h"
#include <time.h>
#include <random>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

Pedido::Pedido() {
	generarModelo();
	generarZona();
	generarColor();
	generarTipo();
	generarConcesionario();
}

void Pedido::generarModelo()
{
	int selectorModelo;
	string modelos[4] = { "M1", "M2", "M3", "M4" };
	selectorModelo = rand() % 4;
	this->modelo = modelos[selectorModelo];
}

void Pedido::generarZona()
{
	int selectorModelo;
	string modelos[3] = { "A", "B", "C" };
	selectorModelo = rand() % 3;
	this->zona = modelos[selectorModelo];
}

void Pedido::generarTipo()
{
	int selectorModelo;
	string modelos[2] = { "Normal", "Prioritario" };
	selectorModelo = rand() % 2;
	this->tipo = modelos[selectorModelo];
}

void Pedido::generarColor()
{
	int selectorColor;
	string colores[3] = { "C1", "C2","C3"};
	selectorColor = rand() % 3;
	this->color = colores[selectorColor];
}
void Pedido::generarConcesionario()
{
	string concesionario;
	int selectorConces;
	string concesionarios[15] = { "C1","C2", "C3","C4", "C5","C6","C7","C8","C9","C10" ,"C11" ,"C12" ,"C13" ,"C14" ,"C15" };

	selectorConces = rand() % 15;
	this->concesionario += concesionarios[selectorConces];
}
void Pedido::mostrar_Pedido() {
	cout << "El color es:  " << color << endl;
	cout << "El modelo es:  " << modelo << endl;
	cout << "El concesionario es: " << concesionario << endl;
	cout << "La zona es: " << zona << endl;
	cout << "El tipo es: " << tipo << endl;
	cout << " ------------------------------------- " << endl;
}

//GETTERS
string Pedido::get_modelo() {
	return this->modelo;
}
string Pedido::get_color() {
	return this->color;
}
string Pedido::get_concesionario() {
	return this->concesionario;
}
string Pedido::get_zona() {
	return this->zona;
}
string Pedido::get_tipo() {
	return this->tipo;
}

//SETTERS
void Pedido::set_modelo(string modelo) {
	this->modelo = modelo;
}
void Pedido::set_color(string color) {
	this->color = color;
}
void Pedido::set_concesionario(string concesionario) {
	this->concesionario = concesionario;
}
void Pedido::set_zona(string zona) {
	this->zona = zona;
}
void Pedido::set_tipo(string tipo) {
	this->tipo = tipo;
}
