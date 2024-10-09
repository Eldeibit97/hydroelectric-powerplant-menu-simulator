#ifndef Pais_hpp
#define Pais_hpp
#include "Central.hpp"
#include <string>
#include <iostream>
using namespace std;

class Pais{

private:
	string nombre;
	double consumoEnergetico;
	Central centralElectrica;
	Central centralElectrica2;

public:
	Pais();
	Pais(string,double,Central,Central);
	double getConsumoEnergetico();
	void setConsumoEnergetico(double);
	Central getCentralElectrica();
	void setCentralElectrica(Central);
	void produccionElectrica();
	void listaDeTrabajadores();
	void revisarPorReparaciones();
	void cambiarEstadoCompuertas();
	void romperCentral();
	void puestosTrabajadores();
	void bonos();
	void marcarCentralReparada();
};

#endif