#pragma once
#include "..\Composite.h"
#include "ComponenteIT.h"
#include "Marco.h"

// Desciende de una clase composite tipo componeteIT
// Va a heredar todo de composite
class Menu : public Composite<ComponenteIT>, public ObjetoIT
{
private:
	int numeroElementos;
	int indiceElementoActual;
	int indiceElementoAnterior;
	bool opcionSalir;
	Marco* marco;

public:
	//Constructor
	Menu(int _x, int _Y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, int _caracterBase);
	
	// Metodos
	void Mostrar();
	bool getTecla();
	void Bucle();
	void Iniciar();
	void MostrarSelector();
	
	//Metodos de acceso
	void setNumeroElementos(int _numeroElementos) { numeroElementos = _numeroElementos; }
	int getNumeroElementos() { return numeroElementos; }

	void setIndiceElementoActual(int _indiceElementoActual) { indiceElementoActual = _indiceElementoActual; }
	int getIndiceElementoActual() { return indiceElementoActual; }

	void setIndiceElementoAnterior(int _indiceElementoAnterior) { indiceElementoAnterior = _indiceElementoAnterior; }
	int getIndiceElementoAnterior() { return indiceElementoAnterior; }
};
