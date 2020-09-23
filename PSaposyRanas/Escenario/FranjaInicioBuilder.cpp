#include "FranjaInicioBuilder.h"

//Creacion de el panel de la franja y asignandole su color
Panel* FranjaInicioBuilder::getPanelFranjaEscenario(MapaElementosPantalla* _mce) {
	Panel* panelFI = new Panel(1, 26, 118, 3, 5, 6, '*', 120, ' ', 0, _mce);
	return panelFI;
}

//Creacion de los bloques propios de la franja almacenados en un vector
vector<Bloques*> FranjaInicioBuilder::getBloquesFranjaEscenario(MapaElementosPantalla* m)
{
	vector<Bloques*> bloquesFI;
	bloquesFI.push_back(new Bloques(1, 26, 20, 2, 'X', 5, 2, m));
	bloquesFI.push_back(new Bloques(50, 26, 10, 2, 'B', 5, 2, m));
	bloquesFI.push_back(new Bloques(99, 26, 20, 2, 'X', 5, 2, m));

	return bloquesFI;
}

//Creacion de las espinas propios de la franja almacenados en un vector
vector<Espinas*> FranjaInicioBuilder::getEspinasFranjaEscenario(MapaElementosPantalla* m)
{
	vector<Espinas*> espinasFI;
	espinasFI.push_back(new Espinas(22, 26, 1, 2, '*', 1, 3, m));
	espinasFI.push_back(new Espinas(61, 26, 1, 2, '*', 1, 3, m));
	espinasFI.push_back(new Espinas(98, 26, 1, 2, '*', 1, 3, m));
	return espinasFI;
}