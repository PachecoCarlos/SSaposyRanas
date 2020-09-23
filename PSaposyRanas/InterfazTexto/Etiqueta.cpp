#include "Etiqueta.h"

//constructor
Etiqueta::Etiqueta(string _texto, int _x, int _y) : ComponenteIT(_x, _y),
texto(_texto)
{
}
// Muestra el texto
void Etiqueta::Mostrar()
{
	if (getVisible()) {
		gotoxy(getX(), getY());
		cout << texto << endl;
	}

}

