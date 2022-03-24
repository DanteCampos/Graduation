#include <iostream>
#include "libforma.h"

int main() {
	Quadrado forma1 = Quadrado(2); // Quadrado de lado = 2
	Circulo forma2 = Circulo(3); // Círculo de raio = 3
	Cilindro forma3 = Cilindro(5, 10); // Cilindro de raio = 5 e altura = 10

	std::cout << forma1.toString() << '\n';
	std::cout << forma2.toString() << '\n';
	std::cout << forma3.toString() << '\n';

	Lista listaFormas = Lista({ &forma1, &forma2, &forma3 }); //Lista de formas
	std::cout << "Quantidade de quadrados = " << listaFormas.qtdeQuadrados() << '\n';
	std::cout << "Quantidade de círculos = " << listaFormas.qtdeCirculos() << '\n';
	std::cout << "Quantidade de cilindros = " << listaFormas.qtdeCilindros() << '\n';
	std::cout << "Áreas: " << listaFormas.mostraAreas() << '\n';
	std::cout << "Volumes: " << listaFormas.mostraVolumes() << '\n';

	Circulo circ = Circulo(5);
	listaFormas.add(&circ);
	std::cout << "Quantidade de círculos = " << listaFormas.qtdeCirculos() << '\n';

	Cilindro cilin = Cilindro(1, 2);
	std::cout << cilin.toString()
		<<"\n Área = " << cilin.calculaArea()
		<< "\n Volume = " << cilin.calculaVolume();
	return 0;
}