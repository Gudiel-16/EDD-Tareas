#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
class actividades
{
public:
	actividades *anterior;
	actividades * siguiente;
	string actividad;
	actividades(string);
	~actividades();
};

