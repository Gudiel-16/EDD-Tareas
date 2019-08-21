#include "dias.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

dias::dias(int _indice, string _dia) //constructor
{
	this->siguiente = NULL;
	this->primeroA = NULL;
	this->ultimoA = NULL;
	this->indice = _indice;
	this->dia = _dia;
}



dias::~dias()
{
}
