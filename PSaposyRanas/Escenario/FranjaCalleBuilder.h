#pragma once
#include "BuilderFranjasEscenario.h"
class FranjaCalleBuilder :
	public BuilderFranjasEscenario
{

	//Metodos de creacion de las partes de la franja reimplementado
	Panel* getPanelFranjaEscenario(MapaElementosPantalla*);
	vector<Bloques*> getBloquesFranjaEscenario(MapaElementosPantalla*);
	vector<Espinas*> getEspinasFranjaEscenario(MapaElementosPantalla*);
};

