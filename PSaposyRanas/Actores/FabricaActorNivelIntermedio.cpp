#include "FabricaActorNivelIntermedio.h"
//inicializacion de los atributos privados
int FabricaActorNivelIntermedio::NumeroEnemigos1 = -1;
int FabricaActorNivelIntermedio::NumeroEnemigos2 = -1;
int FabricaActorNivelIntermedio::NumeroEnemigos3 = -1;
int FabricaActorNivelIntermedio::NumeroEnemigos4 = -1;
int FabricaActorNivelIntermedio::NumeroEnemigos5 = -1;

//inplemetacion de los metodos sobrecargados que retorna la instancia de cada actor
Actor* FabricaActorNivelIntermedio::CrearTortuga(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	NumeroEnemigos1++;
	return new Tortuga(avatarTortuga,_x, _y, _dx * 2, 0, 8, 1, m);
}

Actor* FabricaActorNivelIntermedio::CrearCocodrilo(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	NumeroEnemigos2++;

	return new Cocodrilo(avatarCocodrilo, _x, _y, _dx * 2, 0, 2, 0, m);
}

Actor* FabricaActorNivelIntermedio::CrearAuto1(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	NumeroEnemigos3++;
	return new Auto(avatarAuto1,_x, _y, _dx * 2, 0, 12, 8, m);
}

Actor* FabricaActorNivelIntermedio::CrearAuto2(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	NumeroEnemigos4++;
	return  new Auto(avatarAuto2,_x, _y, _dx * 2, 0, 8, 6, m);
}

Actor* FabricaActorNivelIntermedio::CrearTronco(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	NumeroEnemigos5++;
	return new Auto(avatarTronco, _x, _y, _dx * 2, 0, 1, 3, m);
}

Actor* FabricaActorNivelIntermedio::CrearSapo(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m) {
	return new Sapo(avatarSapo, _x, _y, _dx, _dy, 6, 7, m);
}