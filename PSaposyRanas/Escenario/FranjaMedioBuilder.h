#pragma once
#include "BuilderFranjasEscenario.h"
class FranjaMedioBuilder : public BuilderFranjasEscenario 
{
	//Metodos de creacion de las partes de la franja reimplementados
	Panel* getPanelFranjaEscenario(MapaElementosPantalla*);
	vector<Bloques*> getBloquesFranjaEscenario(MapaElementosPantalla* _mc);
	vector<Espinas*> getEspinasFranjaEscenario(MapaElementosPantalla* _mc);
};