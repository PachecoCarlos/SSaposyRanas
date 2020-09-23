#include "Mosca.h"
#include"ActorMovimientoAleatorio.h"

//Implemetacion del contructor de la clase
Mosca::Mosca(vector<string> _avatar, int _x, int _y, int _dx, int _dy, int _colorCaracter, int _colorFondo, MapaElementosPantalla* m) :
	Actor(_avatar, _x, _y, _dx, _dy, _colorCaracter, _colorFondo, m) {
	movimientoActor = new ActorMovimientoAleatorio(&_avatar, &_x, &_y, &_dx, &_dy, &_colorCaracter, &_colorFondo, m);
}