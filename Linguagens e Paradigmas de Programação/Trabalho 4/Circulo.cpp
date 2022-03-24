#define _USE_MATH_DEFINES
#include "libforma.h"
#include <cmath>
#include <string>

Circulo::Circulo(double raio) {
	this->raio = raio;
}

double Circulo::calculaArea() {
	return M_PI * raio * raio;
}

std::string Circulo::toString() {
	return "Círculo com " + std::to_string(raio) + " de raio";
}