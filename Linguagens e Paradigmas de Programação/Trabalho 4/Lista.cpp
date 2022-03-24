#include "libforma.h"
#include <list>
#include <stdlib.h>
#include <string>
#include <typeinfo>

Lista::Lista() {
	forma = {};
}

Lista::Lista(Forma* forma) {
	this->forma = {forma};
}

Lista::Lista(std::vector<Forma*> formas) {
	forma = {};
	for (auto& it : formas) {
		forma.push_back(it);
	}
}

Lista::~Lista() {
	forma.clear();
}

bool Lista::add(Forma* forma) {
	this->forma.push_back(forma);
	return true;
}

int Lista::qtdeCilindros() {
	int cont = 0;
	for (Forma* it : forma) {
		if (dynamic_cast<Cilindro*>(it) != NULL)
			cont++;
	}
	return cont;
}

int Lista::qtdeCirculos() {
	int cont = 0;
	for (auto& it : forma){
		if (dynamic_cast<Circulo*>(it) != NULL)
			cont++;
	}
	return cont;
}

int Lista::qtdeQuadrados() {
	int cont = 0;
	for (auto& it : forma) {
		if (dynamic_cast<Quadrado*>(it) != NULL)
			cont++;
	}
	return cont;
}

std::string Lista::mostraAreas() {
	std::string retorno = "";
	for (auto& it : forma) {
		retorno += std::to_string(it->calculaArea()) + " ";
	}
	return retorno;
}

std::string Lista::mostraVolumes() {
	std::string retorno = "";
	for (auto& it : forma) {
		retorno += std::to_string(it->calculaVolume()) + " ";
	}
	return retorno;
}

