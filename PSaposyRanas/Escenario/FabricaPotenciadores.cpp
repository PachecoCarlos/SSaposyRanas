#include "FabricaPotenciadores.h"

Potenciadores* FabricaPotenciadores::TipoEnergia = 0;
Potenciadores* FabricaPotenciadores::TipoVida = 0;
Potenciadores* FabricaPotenciadores::TipoVelosidad = 0;
Potenciadores* FabricaPotenciadores::TipoSalto = 0;

void  FabricaPotenciadores::Inicializar(){
	TipoEnergia = new PotenciadoresContretosTipo1(5, 5, 1, 1, '^', 0, 0, 20, 0, 0);
	TipoVida = new PotenciadoresContretosTipo1(10, 10, 1, 1, '!', 0, 0, 0, 0, 1);
	TipoVelosidad = new PotenciadoresContretosTipo2(15, 15, 1, 1, '$', 10, 0, 0, 0, 0);
	TipoSalto = new PotenciadoresContretosTipo2(20, 20, 1, 1, '%', 0, 5, 0, 0, 0);
}

