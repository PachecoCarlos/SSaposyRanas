#include "ComponenteIT.h"

ComponenteIT::ComponenteIT(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase) :
	ObjetoIT(_x, _y, _ancho, _alto, _colorFondoBase, _colorCaracterBase, _caracterBase)
{
}

ComponenteIT::ComponenteIT(int _x, int _y) : ObjetoIT(_x, _y)
{
}
