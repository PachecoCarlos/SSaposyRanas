#include "FabricaActorNivelAvanzado.h"

//inicializacion de los atributos privados
int FabricaActorNivelAvanzado::NumeroEnemigosA1 = -1;
int FabricaActorNivelAvanzado::NumeroEnemigosA2 = -1;
int FabricaActorNivelAvanzado::NumeroEnemigosA3 = -1;
int FabricaActorNivelAvanzado::NumeroEnemigosA4 = -1;
int FabricaActorNivelAvanzado::NumeroEnemigosA5 = -1;

//inplemetacion de los metodos sobrecargados que retorna la instancia de cada actor
Actor* FabricaActorNivelAvanzado::CrearTortuga(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	NumeroEnemigosA1++;
	return new Tortuga(avatarTortuga,_x, _y, _dx * 3, 0, 2, 5, m);
}

Actor* FabricaActorNivelAvanzado::CrearCocodrilo(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	NumeroEnemigosA2++;
	return new Cocodrilo(avatarCocodrilo, _x, _y, _dx * 3, 0, 4, 0, m);
}

Actor* FabricaActorNivelAvanzado::CrearAuto1(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	NumeroEnemigosA3++;
	return new Auto(avatarAuto1,_x, _y, _dx * 3, 0, 3, 10, m);
}

Actor* FabricaActorNivelAvanzado::CrearAuto2(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	NumeroEnemigosA4++;
	return  new Auto(avatarAuto2,_x, _y, _dx * 3, 0, 1, 2, m);
}

Actor* FabricaActorNivelAvanzado::CrearTronco(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	NumeroEnemigosA5++;
	return new Auto(avatarTronco, _x, _y, _dx * 3, 0, 1, 8, m);
}

Actor* FabricaActorNivelAvanzado::CrearSapo(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	return new Sapo(avatarSapo, _x, _y, _dx, _dy, 6, 7, m);
}