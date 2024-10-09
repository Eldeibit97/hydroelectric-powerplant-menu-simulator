#ifndef Central_hpp
#define Central_hpp
#include "Presa.hpp"
#include "Trabajador.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Central{

private:
	string nombre;
	bool estado; //False por defecto
	float produccionElectrica;
	Presa presa;
	vector <Trabajador> trabajadores;

public:
	Central();
	Central(string,float,string); //Usar el setTrabajador para construir a los trabajadores
	void setProduccionElectrica(double);
	double getProduccionElectrica();
	void setTrabajador(string,string);
	bool getEstado();
	void setEstado();
	void setPuertasPresa(); 
	bool getPuertasPresa();
	void imprimirTrabajadores();
	int reparaciones();
	string getNombre();
	void sortTrabajadores();
	void setDisponibilidadTrabajador(int);
	bool getDisponibilidadTrabajador(int);
	void imprimirBonos();
	vector<Trabajador> liberarTrabajadores();
};

#endif

