#include "Actor.h"
#include"Cocodrilo.h"
#include"Tortuga.h"
#include"Auto.h"
#include"Sapo.h"

int Actor::numeroActores = 0;

//metodo accesor que retorna numero de actores
int Actor::getNumeroActores() {
	return numeroActores;
}

//implementacion del constructor de la clase actor
Actor::Actor(vector<string> _avatar, int _x, int _y, int _dx, int _dy,
	int _colorCaracter, int _colorFondo, MapaElementosPantalla* _mce) :
	x(_x), y(_y), dx(_dx), dy(_dy),
	colorCaracter(_colorCaracter), colorFondo(_colorFondo), mapaElementosPatalla(_mce) {
	nombre = "";
	avatar = _avatar;
	numeroActores++;
	numero = numeroActores;
	vidas = 3;
	puntos = 0;
	// instanciamos ActorMovimiento para que las clase hijas deteminen el tipo de movimiento
	movimientoActor = new ActorMovimiento(&_avatar, &_x, &_y, &_dx, &_dy, &_colorCaracter, &_colorFondo, _mce);
}


void Actor::Mostrar() {
	// Llamando al metodo Mostrar de ActorMovimiento
	movimientoActor->Mostrar();
}

void Actor::Mover() {
	// Llamando al metodo Mover de ActorMovimiento
	movimientoActor->Mover();
}

// Implementacion del Patron Factory Method
//Actor* Actor::getActor(string nombre, int _x, int _y, int _dx, int _dy){
//	if (nombre == "Sapo") 
//		return new Sapo({ {"\\o/"}, {"_O_"} }, _x, _y, _dx, _dy, 1, 27, 1, 119, 1, 4);
//	else if (nombre == "Tortuga")
//		return new Tortuga({
//		  {" ______   ____"},
//		  {"/      \\ | o |"},
//		  {"|      |/___\\|"},
//		  {"|______ /     "} } , _x, _y, _dx, _dy, 1, 27, 1, 119, 2, 6);
//	else if (nombre == "Cocodrilo")
//		return new Cocodrilo({
//		{"           /^^^^\\                "},
//		{" /^^\\____/0      \\               "},
//		{"(                 `-------^^^^^^^"},
//		{" V^V^V^V^V^V^\\..................."} } , _x, _y, _dx, _dy,1, 27, 1, 119, 5, 7);
//	else if (nombre == "Auto")
//		return new Auto({
//		{"  ______     "},
//		{" /|_||_\\`.__ "},
//		{"(_  _    _  \\"},
//		{"=`-(_)--(_)-' "} }, _x, _y, _dx, _dy, 1, 27, 1, 119, 8, 1);
//	else
//		return NULL;
//}