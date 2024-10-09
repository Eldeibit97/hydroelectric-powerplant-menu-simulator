#ifndef Trabajador_hpp
#define Trabajador_hpp
#include <string>
#include <iostream>
using namespace std;

class Trabajador{

private:
	string nombre;
	string puesto;
	bool disponibilidad;
	double sueldo;

public:
	Trabajador();
	Trabajador(string,string);
	string getNombre();
	string getPuesto();
	bool getDisponibilidad();
	double getSueldo();
	void setSueldo(double);
	void setNombre(string);
	void setPuesto(string);
	void setDisponibilidad();
	~Trabajador();	
};

#endif