#include "Pais.hpp"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

//TIENE ACCESO A LA CLASE TRABAJADOR

Pais::Pais(){};

Pais::Pais(string cNombre,double cConsumoEnergetico, Central cCentralElectrica,Central cCentralElectrica2){
	nombre = cNombre;
	consumoEnergetico = cConsumoEnergetico;
	centralElectrica = cCentralElectrica;
	centralElectrica2 = cCentralElectrica2;
};

double Pais::getConsumoEnergetico(){
	return consumoEnergetico;
};

void Pais::setConsumoEnergetico(double cConsumoEnergetico){  //chance y se borra
	consumoEnergetico = cConsumoEnergetico;
}


void Pais::produccionElectrica(){
	cout << "La produccion electrica total de " << centralElectrica.getNombre() << " es " << centralElectrica.getProduccionElectrica() << "MW" << endl;
	cout << "La produccion electrica total de " << centralElectrica2.getNombre() << " es " << centralElectrica2.getProduccionElectrica() << "MW" << endl;
	cout << "La produccion electrica total de las centrales es " << centralElectrica.getProduccionElectrica() + centralElectrica2.getProduccionElectrica() << endl;
	if(consumoEnergetico - centralElectrica.getProduccionElectrica() > 0){
		cout << "Faltan " << consumoEnergetico - centralElectrica.getProduccionElectrica() - centralElectrica2.getProduccionElectrica() << " para satisfacer la demanda energetica del pais." << endl;
	}else{
		cout << "La produccion se paso de energia por " << abs(consumoEnergetico - centralElectrica.getProduccionElectrica() - centralElectrica2.getProduccionElectrica()) << endl;
	}
};

void Pais::listaDeTrabajadores(){
	int opcion;
	cout << "Trabajadores de la central: 1. "<< centralElectrica.getNombre() << " 2. " << centralElectrica2.getNombre() << " 3. Ambas" << endl;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		centralElectrica.imprimirTrabajadores();
		break;
	case 2:
		centralElectrica2.imprimirTrabajadores();
		break;
	case 3:
		centralElectrica.imprimirTrabajadores();
		cout << endl;
		centralElectrica2.imprimirTrabajadores();
		break;
	default:
		cout << "El valor ingresado no esta entre las opciones.";
		cout << endl;
		break;
	}
};

void Pais::revisarPorReparaciones(){
	if(centralElectrica.getEstado()){
		cout << centralElectrica.getNombre() << " esta en estado funcional." << endl;
	}else if(!(centralElectrica.getDisponibilidadTrabajador(0))){
		cout << centralElectrica.getNombre() << " ya esta siendo reparada. Desea delagar mas trabajadores: 1. Si 2. No " << endl;
		int opcion = 0;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			centralElectrica.setDisponibilidadTrabajador(centralElectrica.reparaciones());
			centralElectrica.setDisponibilidadTrabajador(centralElectrica.reparaciones());
			cout << "Ahora todos los reparadores estan ocupados" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	}
	else{
		cout << centralElectrica.getNombre() << " necesita reparaciones." << endl;
		centralElectrica.setDisponibilidadTrabajador(centralElectrica.reparaciones());
		centralElectrica.setDisponibilidadTrabajador(centralElectrica.reparaciones());
		centralElectrica.setDisponibilidadTrabajador(centralElectrica.reparaciones());
	}
	if(centralElectrica2.getEstado()){
		cout << centralElectrica2.getNombre() << " esta en estado funcional." << endl;
	}else if(!(centralElectrica2.getDisponibilidadTrabajador(0))){
		cout << centralElectrica2.getNombre() << " ya esta siendo reparada. Desea delagar mas trabajadores: 1. Si 2. No " << endl;
		int opcion = 0;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			centralElectrica2.setDisponibilidadTrabajador(centralElectrica2.reparaciones());
			centralElectrica2.setDisponibilidadTrabajador(centralElectrica2.reparaciones());
			cout << "Ahora todos los reparadores estan ocupados" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	}
	else{
		cout << centralElectrica2.getNombre() << " necesita reparaciones." << endl;
		centralElectrica2.setDisponibilidadTrabajador(centralElectrica2.reparaciones());
		centralElectrica2.setDisponibilidadTrabajador(centralElectrica2.reparaciones());
		centralElectrica2.setDisponibilidadTrabajador(centralElectrica2.reparaciones());
	}
};


void Pais::cambiarEstadoCompuertas(){
	int opcion;
	cout << "Abrir compuertas: 1. "<< centralElectrica.getNombre() << " 2. " << centralElectrica2.getNombre();
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		if(centralElectrica.getPuertasPresa()){
		cout << "Abriendo compuertas de " << centralElectrica.getNombre() << endl;
		centralElectrica.setPuertasPresa();
		}else{
			cout << "Cerrando compuertas de " << centralElectrica.getNombre() << endl;
			centralElectrica.setPuertasPresa();
		}
		break;
	case 2:
		if(centralElectrica2.getPuertasPresa()){
		cout << "Abriendo compuertas de " << centralElectrica2.getNombre() << endl;
		centralElectrica.setPuertasPresa();
		}else{
			cout << "Cerrando compuertas de " << centralElectrica2.getNombre() << endl;
			centralElectrica2.setPuertasPresa();
		}
	default:
		cout << "El valor ingresado no esta entre las opciones.";
		break;
	}
};

void Pais::romperCentral(){
	centralElectrica.setEstado();
}

void Pais:: puestosTrabajadores(){
	cout << "Empleados ordenados por puestos" << endl;
	cout << endl;
	centralElectrica.sortTrabajadores();
	cout << endl;
	centralElectrica2.sortTrabajadores();
	cout << endl;
};

void Pais:: bonos(){
	int opcion;
	cout << " Bonos de los trabajadores de la central: 1. "<< centralElectrica.getNombre() << " 2. " << centralElectrica2.getNombre() << " 3. Ambas" << endl;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		centralElectrica.imprimirBonos();
		break;
	case 2:
		centralElectrica2.imprimirBonos();
		break;
	case 3:
		centralElectrica.imprimirBonos();
		cout << endl;
		centralElectrica2.imprimirBonos();
		break;
	default:
		cout << "El valor ingresado no esta entre las opciones.";
		cout << endl;
		break;
	}
}

void Pais::marcarCentralReparada(){
	int opcion;
	cout << "Central para marcar como repara: 1. "<< centralElectrica.getNombre() << " 2. " << centralElectrica2.getNombre() << endl;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		centralElectrica.setEstado();
		for(int i = 0; i < centralElectrica.liberarTrabajadores().size(); i++){
			if(centralElectrica.liberarTrabajadores().at(i).getPuesto() == "Mantenimiento" && !(centralElectrica.liberarTrabajadores().at(i).getDisponibilidad())){
				centralElectrica.setDisponibilidadTrabajador(i);
				}
		}
		break;
	case 2:
		centralElectrica2.setEstado();
		for(int i = 0; i < centralElectrica2.liberarTrabajadores().size(); i++){
			if(centralElectrica2.liberarTrabajadores().at(i).getPuesto() == "Mantenimiento" && !(centralElectrica2.liberarTrabajadores().at(i).getDisponibilidad())){
				centralElectrica2.setDisponibilidadTrabajador(i);
				}
		}
		break;
	default:
		cout << "El valor ingresado no esta entre las opciones.";
		cout << endl;
		break;
	}
}