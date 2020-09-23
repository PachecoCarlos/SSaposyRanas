#pragma once
#include "BuilderFranjasEscenario.h"
class FranjaRioBuilder :
	public BuilderFranjasEscenario
{
	//Metodos de creacion de las partes de la franja
	Panel* getPanelFranjaEscenario(MapaElementosPantalla*);
	vector<Bloques*> getBloquesFranjaEscenario(MapaElementosPantalla*);
	vector<Espinas*> getEspinasFranjaEscenario(MapaElementosPantalla*);
};

