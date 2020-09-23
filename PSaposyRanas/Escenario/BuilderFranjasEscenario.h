#pragma once
#include"../InterfazTexto/Panel.h"
#include "Bloques.h"
#include "Espinas.h"
#include "../Actores/Auto.h"
#include "../Actores/Tortuga.h"
#include <vector>

// Clase abstracta pura
class BuilderFranjasEscenario
{
public:
	// Cambiamos la clase superficie por la clase Panel y usamos MapaElementosPantalla para guardar caracter, color y posiciones
	virtual Panel* getPanelFranjaEscenario(MapaElementosPantalla*) = 0;
	virtual vector<Bloques*> getBloquesFranjaEscenario(MapaElementosPantalla*) = 0;
	virtual vector<Espinas*> getEspinasFranjaEscenario(MapaElementosPantalla*) = 0;
};

