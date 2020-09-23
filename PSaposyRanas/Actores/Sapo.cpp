#include "Sapo.h"

//Implemetacion del contructor de la clase
Sapo::Sapo(vector<string> _avatar, int _x, int _y, int _dx, int _dy, int _colorCaracter, int _colorFondo, MapaElementosPantalla* m)
	:Actor(_avatar, _x, _y, _dx, _dy, _colorCaracter, _colorFondo, m) {
	// Asignamos objeto de ActorMovimientoNormal a movimientoActor que es un atributo de actor, los parametros lo pasamos por referencia
	movimientoActor = new ActorMovimientoNormal(&_avatar, &_x, &_y, &_dx, &_dy, &_colorCaracter, &_colorFondo, m);
}