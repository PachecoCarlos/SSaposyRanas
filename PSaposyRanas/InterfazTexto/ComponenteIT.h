#pragma once
#include "ObjetoIT.h"

//Clase abstracta a partir de la cual se crearan otras clases especificas
class ComponenteIT : public ObjetoIT
{

public:
	// se crean dos contructores segun se necesite
	ComponenteIT(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterFondoBase);
	ComponenteIT(int _x, int _y);
	ComponenteIT() {};
	virtual void Mostrar() = 0;
};
