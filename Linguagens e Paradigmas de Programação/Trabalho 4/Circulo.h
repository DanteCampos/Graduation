#pragma once
#include "libforma.h"
#include <string>

class Circulo: public FormaBidimensional{
private:
	double raio;
public:
	Circulo (double raio);
	double calculaArea();
	std::string toString();
};

