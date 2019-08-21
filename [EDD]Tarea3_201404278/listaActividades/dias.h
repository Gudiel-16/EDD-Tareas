#pragma once
#include "actividades.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class dias
{
public:
	dias *siguiente;
	actividades *primeroA; //puntero a la lista actividades
	actividades *ultimoA; //puntero a la lista actividades
	int indice; //0=lunes, 1=martes, 2=miercoles, 3=jueves, 4=viernes, 5=sabado, 6=domingo
	string dia;
	dias(int,string);
	~dias();
};

