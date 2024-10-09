#include "Presa.hpp"

Presa::Presa(){
	puertasCerradas = true;
};

bool Presa::getPuertasCerradas(){
	return puertasCerradas;
};

void Presa::setPuertasCerradas(){
	puertasCerradas = !puertasCerradas;
}

