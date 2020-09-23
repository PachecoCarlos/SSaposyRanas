#include "Aguila.h"
#include "Utilitarios.h"


Aguila::Aguila(string _NombreAguila, string _RepresentacionVisual, int _PosicionXI, int _PosicionXD, int _PosicionYS, int _PosicionYI): NombreAguila(_NombreAguila), RepresentacionVisual(_RepresentacionVisual),
PosicionXI(_PosicionXI), PosicionXD(_PosicionXD),
PosicionYS(_PosicionYS), PosicionYI(_PosicionYI)
{
}

void Aguila::VisualizarEnPantalla()
{
	gotoxy(PosicionXI, PosicionYI);
	cout << RepresentacionVisual << "\nBBBBB" << "\nAAAAAA" <<  endl;
	
}
