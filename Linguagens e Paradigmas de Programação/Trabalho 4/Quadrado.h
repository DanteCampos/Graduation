#pragma once
#include "libforma.h"
#include <string>

class Quadrado: public FormaBidimensional{
private:
	double lado;
public:
	Quadrado(double lado);
	double calculaArea();
	std::string toString();
};

