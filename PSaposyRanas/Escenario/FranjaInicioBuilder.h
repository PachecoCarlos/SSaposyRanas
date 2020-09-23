#pragma once
#include "BuilderFranjasEscenario.h"
class FranjaInicioBuilder :
	public BuilderFranjasEscenario
{
	//Metodos de creacion de las partes de la franja reimplementado
	Panel* getPanelFranjaEscenario(MapaElementosPantalla* _mce);
	vector<Bloques*> getBloquesFranjaEscenario(MapaElementosPantalla*);
	vector<Espinas*> getEspinasFranjaEscenario(MapaElementosPantalla*);
};

