#include "FranjaRioBuilder.h"

//Creacion de el panel de la franja y asignandole su color
Panel* FranjaRioBuilder::getPanelFranjaEscenario(MapaElementosPantalla* _mce)
{
	Panel* superficieFI = new Panel(1, 3, 118, 11, 1, 128, 178, 120, ' ', 0, _mce);

	return superficieFI;
}

//Creacion de los bloques propios de la franja almacenados en un vector
vector<Bloques*> FranjaRioBuilder::getBloquesFranjaEscenario(MapaElementosPantalla* m) {
	vector<Bloques*> bloquesFI;
	return bloquesFI;
}

//Creacion de las espinas propias de la franja almacenados en un vector
vector<Espinas*> FranjaRioBuilder::getEspinasFranjaEscenario(MapaElementosPantalla* m) {
	return vector<Espinas*>();
}