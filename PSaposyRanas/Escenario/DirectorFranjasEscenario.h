#pragma once
#include "BuilderFranjasEscenario.h"
#include "FranjasEscenario.h"

class DirectorFranjasEscenario{
private:
	BuilderFranjasEscenario* builder;
public:
	void setBuilder(BuilderFranjasEscenario* _builder) { builder = _builder; }

	//Definicion del metodo que construira las franjas
	FranjasEscenario* getFranjaEscenario(MapaElementosPantalla*_mce);
};

