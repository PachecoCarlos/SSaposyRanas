#pragma once
#include "SeleccionObjetoIT.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "../Utilitarios.h"

using namespace std;
// desciende de SeleccionObjetoIT
class ObjetoSalir :
	public SeleccionObjetoIT
{
public:
	bool pres = false;
	void presEnter() {
		pres = true;
	}
	bool fin() {
		return pres;
	}
};