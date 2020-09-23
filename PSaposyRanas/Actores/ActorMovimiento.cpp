#include "ActorMovimiento.h"
//Definimos los limites para el movimiento del actor
int ActorMovimiento::limiteSuperior = 1;
int ActorMovimiento::limiteInferior = 28;
int ActorMovimiento::limiteIzquierda = 1;
int ActorMovimiento::limiteDerecha = 119;

// Inicializando las variables propias de la clase
ActorMovimiento::ActorMovimiento(vector<string>* _avatar, int* _x, int* _y, int* _dx, int* _dy, int* _colorCaracter, int* _colorFondo, MapaElementosPantalla* _mce) :
	avatar(*_avatar), x(*_x), y(*_y), dx(*_dx), dy(*_dy), colorCaracter(*_colorCaracter), colorFondo(*_colorFondo), mapaElementos(_mce) {
	filasAvatar = ObtenerNumeroFilasAvatar();
	int numeroColumnas = 0;
	columnasAvatar = 0;

	// metodo para obtener el ancho de un actor
	for (int i = 0; i < filasAvatar; i++) {
		numeroColumnas = (avatar[i].size());
		if (numeroColumnas > columnasAvatar) {
			columnasAvatar = numeroColumnas;
		}
	}

}
