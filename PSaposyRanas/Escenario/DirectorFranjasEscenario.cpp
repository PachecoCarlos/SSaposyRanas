#include "DirectorFranjasEscenario.h"

// El director te crea una franja con los objetos que tu le dices y te retorna un franja 
FranjasEscenario* DirectorFranjasEscenario::getFranjaEscenario(MapaElementosPantalla* _mce)
{
	FranjasEscenario* franjaEscenario = new FranjasEscenario;

	franjaEscenario->setPanelFE(builder->getPanelFranjaEscenario(_mce));
	franjaEscenario->setBloquesFE(builder->getBloquesFranjaEscenario(_mce));
	franjaEscenario->setEspinasFE(builder->getEspinasFranjaEscenario(_mce));

	return franjaEscenario;
}
