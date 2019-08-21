#include "actividades.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

actividades::actividades(string _actividad)
{
	this->anterior = NULL;
	this->siguiente = NULL;
	this->actividad = _actividad;
}


actividades::~actividades()
{
}
