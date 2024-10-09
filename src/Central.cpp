#include "Central.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Central::Central(){};
Central::Central(string cNombre, float cProduccion,string fichero){
	nombre = cNombre;
	estado = true;
	produccionElectrica = cProduccion;
	ifstream archivoTrabajadores;
	archivoTrabajadores.open(fichero);
	int N = 0;
	archivoTrabajadores >> N;
	for(int i = 0;i < N ; i++){
		archivoTrabajadores.ignore();
		string nombreTrabajador;
		string puesto;
		getline(archivoTrabajadores,nombreTrabajador);
		archivoTrabajadores >> puesto;
		setTrabajador(nombreTrabajador,puesto);
	}
	archivoTrabajadores.close();
};


void Central::setProduccionElectrica(double cProduccion){
	produccionElectrica = cProduccion;
}

double Central::getProduccionElectrica(){
	return produccionElectrica;
}


void Central::setTrabajador(string cNombre,string cPuesto){
	Trabajador tra(cNombre,cPuesto);
	trabajadores.push_back(tra);
};

bool Central::getEstado(){
	return estado;
}

void Central::setEstado(){
	estado = !estado;
}

void Central::setPuertasPresa(){
	presa.setPuertasCerradas();
}

bool Central::getPuertasPresa(){
	return presa.getPuertasCerradas();
}


void Central::imprimirTrabajadores(){
	cout << "Lista de Trabajadores de la central " << nombre << endl;
	cout << endl;
	for(auto e:trabajadores){
		cout << "Nombre: " << e.getNombre() << endl;
		cout << "Puesto: " << e.getPuesto() << endl;
		cout << "Disponibilidad: " << (e.getDisponibilidad() ? "Disponible":"No Disponible") << endl;
		cout << endl;
	}
}

void Central::sortTrabajadores(){
	cout << "Trabajadores de mantenimiento de " << nombre << endl;
	cout << endl;
	for(auto& e:trabajadores){
		if(e.getPuesto() == "Mantenimiento"){
			cout << e.getNombre() << endl;
		}
	}
	cout << endl;
	cout << "Trabajadores de operaciones de " << nombre << endl;
	cout << endl;
	for(auto& e:trabajadores){
		if(e.getPuesto() == "Operador"){
			cout << e.getNombre() << endl;
		}
	}
}

int Central::reparaciones(){
	for(int i = 0; i < trabajadores.size(); i++){
		if(trabajadores.at(i).getPuesto() == "Mantenimiento" && trabajadores.at(i).getDisponibilidad()){
			cout << trabajadores.at(i).getNombre() << " es uno de los encargados de la reparacion." << endl;
			return i;
		}
	}
	return 0;
}

string Central::getNombre(){
	return nombre;
}

void Central::setDisponibilidadTrabajador(int i){
	trabajadores.at(i).setDisponibilidad();
}

bool Central::getDisponibilidadTrabajador(int i){
	return trabajadores.at(i).getDisponibilidad();
}

void Central::imprimirBonos(){
	cout << "Sueldo + Bonos para cada empleado (Bono de 20% se aplica si el trabajador se encuentra trabajando/No Disponible) " << nombre << endl;
	cout << endl;
	for(auto e:trabajadores){
		cout << "Nombre: " << e.getNombre() << endl;
		cout << "Puesto: " << e.getPuesto() << endl;
		cout << "Sueldo: " << e.getSueldo() << endl;
		if(e.getDisponibilidad()){
			cout << "Bono: " << 0 << endl;
		}else{
			cout << "Bono: " << e.getNombre() << " se encuentra trabajando. Es acreedor a un bono de " << e.getSueldo() * .2 << endl;
		}
		cout << endl;
	}
}

vector<Trabajador> Central::liberarTrabajadores(){
	return trabajadores;
}
