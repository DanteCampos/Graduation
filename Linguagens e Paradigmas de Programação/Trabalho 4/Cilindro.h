#pragma once
#include "libforma.h"
#include <string>

class Cilindro: public FormaTridimensional{
private:
	double raioBase;
	double altura;
public:
	Cilindro(double raioBase, double altura);
	double calculaArea();
	double calculaVolume();
	std::string toString();
};

