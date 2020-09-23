#pragma once
#include "Potenciadores.h"
#include "PotenciadoresContretosTipo1.h"
#include "PotenciadoresContretosTipo2.h"


class FabricaPotenciadores
{
private:
	static Potenciadores* TipoEnergia;
	static Potenciadores* TipoVida;
	static Potenciadores* TipoVelosidad;
	static Potenciadores* TipoSalto;

public:
	static void  Inicializar();

	static Potenciadores* getObjetoTipoEnergia(){ return TipoEnergia->Clonar(); }
	static Potenciadores* getObjetoTipoVida(){	return TipoVida->Clonar(); }
	static Potenciadores* getObjetoTipoVelocidad(){ return TipoVelosidad->Clonar(); }
	static Potenciadores* getObjetoTipoSalto(){	return TipoSalto->Clonar(); }

};

