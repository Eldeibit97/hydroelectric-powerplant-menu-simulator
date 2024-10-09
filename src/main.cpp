#include "Pais.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

Central datosCentral(){
	string nombreCentral;
	float produccionElectrica;
	string fichero;
	cout << "Nombre de la central: ";
	getline(cin,nombreCentral);
	cout << "Produccion electrica anual aproximada en MW hora: ";
	while(true){
		if (!(cin >> produccionElectrica)){
            cout << "Tipo de dato no valido." << endl;
            cout << endl;
            cin.clear();
            cin.ignore();
			cout << "Produccion electrica anual aproximada en MW hora: ";
        }else if(produccionElectrica < 0){
			cout << "Tipo de dato no valido." << endl;
            cout << endl;
            cin.clear();
            cin.ignore();
			cout << "Produccion electrica anual aproximada en MW hora: ";
		}
		else{
			break;
		}
	}
	cout << "Nombre del fichero con los trabajadores: ";
	ifstream file;
	while(true){
		cin >> fichero;
		file.open(fichero);
		if (file){
            file.close();
			break;
        }else{
			cout << "El fichero no existe. Intentar de nuevo." << endl;
			cout << "Nombre del fichero con los trabajadores: ";
		}
	};
	cout << endl;
	Central central(nombreCentral,produccionElectrica,fichero);
	cin.ignore();
	return central;
}

int menu(Pais mexico) {
	cout << endl;
    int opcion;
    while (true) {
        cout << "Menu de opciones de manejo de las centrales hidroelectricas en Mexico:" << endl;
        cout << "1. Obtener una lista de los trabajadores de las centrales." << endl;
        cout << "2. Ordenar a los trabajadores por sus puestos." << endl;
		cout << "3. Obtener los bonos a los que cada trabajador tiene derecho" << endl;
        cout << "4. Aproximar la satisfaccion energetica en Mexico con el uso de las centrales hidroelectricas." << endl;
        cout << "5. Detectar malfuncionamientos en las centrales y repararlos de ser necesario." << endl;
        cout << "6. Abrir o cerrar las compuertas de una de las presas. " << endl;
		cout << "7. Marcar Central como reparada. " << endl;
        cout << "8. POR RAZONES DEMOSTRATIVAS AVERIAR CENTRAL 1." << endl;
        cout << "9. Salir del programa." << endl;

        if (!(cin >> opcion)) {
            cout << "Tipo de dato no valido. Por favor solo introducir numero enteros dentro del rango." << endl;
            cout << endl;
            cin.clear();
            cin.ignore();
            menu(mexico);
        }
        switch (opcion) {
        case 1:
            mexico.listaDeTrabajadores();
            cout << endl;
            break;
        case 2:
            mexico.puestosTrabajadores();
            cout << endl;
            break;
		case 3:
			mexico.bonos();
			cout << endl;
            break;
        case 4:
            mexico.produccionElectrica();
            cout << endl;
            break;
        case 5:
            mexico.revisarPorReparaciones();
            cout << endl;
            break;
        case 6:
            mexico.cambiarEstadoCompuertas();
            cout << endl;
            break;
		case 7:
            mexico.marcarCentralReparada();
            cout << endl;
            break;
        case 8:
            mexico.romperCentral();
            cout << endl;
            break;
        case 9:
            cout << endl;
            return 0;
        default:
            cout << "Favor de introducir una opcion valida." << endl;
        	cout << endl;
            break;
        }
    }
}


int main(){
	cout << "Sistema de manejo de centrales hidraulicas de Mexico" << endl;
	cout << "Carga los datos de las diferentes centrales" << endl;
	//Central central1("El Novillo",135,"personas.txt");
	//Central central2("El Cajon",750,"personas2.txt");
	Central central1 = datosCentral();
	Central central2 = datosCentral();
	Pais mexico("Mexico",235000,central1,central2);

	menu(mexico);
	
	cout << "SALISTE DEL PROGRAMA" << endl;

	return 0;
}   