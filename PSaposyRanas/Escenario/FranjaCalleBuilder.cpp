#include "FranjaCalleBuilder.h"

//Creacion de el panel de la franja y asignandole su color
Panel* FranjaCalleBuilder::getPanelFranjaEscenario(MapaElementosPantalla*m){
	Panel* superficieFI = new Panel(1, 17, 118, 9, 0, 15, ' ', 120, ' ', 0, m);
	superficieFI->setColorFondoBorde(5);
	return superficieFI;
}

//Creacion de los bloques propios de la franja almacenados en un vector
vector<Bloques*> FranjaCalleBuilder::getBloquesFranjaEscenario(MapaElementosPantalla* m) {
	vector<Bloques*> bloquesFI;
	bloquesFI.push_back(new Bloques(1,   21, 20, 1, '>', 10, 1, m));
	bloquesFI.push_back(new Bloques(30,  21, 10, 1, '=', 10, 1, m));
	bloquesFI.push_back(new Bloques(50,  21, 20, 1, '>', 10, 1, m));
	bloquesFI.push_back(new Bloques(80,  21, 10, 1, '=', 10, 1, m));
	bloquesFI.push_back(new Bloques(100, 21, 10, 1, '>', 10, 1, m));

	return bloquesFI;
}

//Creacion de las espinas propias de la franja almacenados en un vector
vector<Espinas*> FranjaCalleBuilder::getEspinasFranjaEscenario(MapaElementosPantalla* m)
{
	return vector<Espinas*>();
}
