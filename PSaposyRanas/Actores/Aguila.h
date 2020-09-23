#pragma once
#include <iostream>

using namespace std;

class Aguila
{
	//atributos propios de la clase de tipo privado
private:
	string NombreAguila;
	string RepresentacionVisual;
	int PosicionXI;
	int PosicionXD;
	int PosicionYS;
	int PosicionYI;
public:
	//constructor de la clase publica
	Aguila(string Nombre, string RepresentacionVisual, int _PosicionXI, int _PosicionXD, int _PosicionYS, int PosicionYI);
	//metodos publicos declarados de la clase
	void VisualizarEnPantalla();
	void AtraparAnimal() {};
};

