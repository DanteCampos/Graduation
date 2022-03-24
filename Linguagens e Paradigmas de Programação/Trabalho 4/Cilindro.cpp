#define _USE_MATH_DEFINES
#include "libforma.h"
#include <cmath>
#include <string>

Cilindro::Cilindro(double raioBase, double altura) {
	this->raioBase = raioBase;
	this->altura = altura;
}

double Cilindro::calculaArea() {
	return 2*altura*raioBase*M_PI + 2*raioBase*raioBase*M_PI;
}

double Cilindro::calculaVolume() {
	return M_PI*raioBase*raioBase*altura;
}

std::string Cilindro::toString() {
	return "Cilindro com " + std::to_string(altura) +
		" de altura e " + std::to_string(raioBase) +
		" de raio da base";
}