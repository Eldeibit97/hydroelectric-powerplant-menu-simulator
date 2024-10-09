#include "Trabajador.hpp"
#include <string>
#include <iostream>
using namespace std;

Trabajador::Trabajador(){};

Trabajador::Trabajador(string cNombre, string cPuesto){
	nombre = cNombre;
	puesto = cPuesto;
	disponibilidad = true;
	sueldo = 15000;
};

string Trabajador::getPuesto(){
	return puesto;
};

string Trabajador::getNombre(){
	return nombre;
};

bool Trabajador::getDisponibilidad(){
	return disponibilidad;
};

void Trabajador::setNombre(string cNombre){
	nombre = cNombre;
};

void Trabajador::setPuesto(string cPuesto){
	puesto = cPuesto;
};

void Trabajador::setDisponibilidad(){
	disponibilidad = !disponibilidad;
};

double Trabajador::getSueldo(){
	return sueldo;
}

void Trabajador::setSueldo(double cSueldo){
	sueldo = cSueldo;
}
 
Trabajador::~Trabajador(){};