#pragma once
#include "libforma.h"
#include <list>
#include <string>
#include <vector>

class Lista{
private:
	std::list<Forma*> forma;
public:
	Lista();
	Lista(Forma* forma);
	Lista(std::vector<Forma*> formas);
	~Lista();
	bool add(Forma* forma);
	int qtdeCirculos();
	int qtdeCilindros();
	std::string mostraAreas();
	std::string mostraVolumes();
	int qtdeQuadrados();
};

