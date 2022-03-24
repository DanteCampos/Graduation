#include "libforma.h"
#include <string>

Quadrado::Quadrado(double lado) {
	this->lado = lado;
}

double Quadrado::calculaArea() {
	return lado * lado;
}

std::string Quadrado::toString() {
	return "Quadrado com " + std::to_string(lado) + " em cada lado";
}