#pragma once
// clase Abstracta para seleccionar un objeto
class SeleccionObjetoIT
{
public:
	virtual void presEnter() = 0;
	virtual bool fin() = 0;
};