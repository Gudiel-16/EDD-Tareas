#include "dias.h"
#include "actividades.h"
#include <iostream>
#include <stdlib.h>
#include <string>

void insertarActividad(string,string);
void insertarOrdenadoDia(int,string);
void insertarNodoRaiz();
void enlazarActividad(int,string);
bool buscarDia();

dias *miRaiz; //primer nodo de la lista dias


void insertarNodoRaiz()
{
	miRaiz = new dias(-1, "raiz"); //funcion que sera la primera en llamar, para tener raiz
}


void enlazarActividad(int _dia, string _actividad)
{
	dias* aux = miRaiz->siguiente;
	
	while (aux!=NULL)
	{
		if (_dia==aux->indice)
		{
			actividades *nuevo = new actividades(_actividad);
			if (aux->primeroA==NULL)
			{
				nuevo->anterior = NULL;
				nuevo->siguiente = NULL;
				aux->primeroA = nuevo;
				aux->ultimoA = nuevo;
			}
			else{
				nuevo->siguiente = NULL;
				nuevo->anterior = aux->ultimoA;
				aux->ultimoA->siguiente = nuevo;
				aux->ultimoA = nuevo;
			}
		}

		aux = aux->siguiente;
	}
}

void insertarOrdenadoDia(dias *nuevo, dias *raiz)
{
	dias *temp = miRaiz;
	bool bandera = false;
	bool yaExisteDia = false;

	while (true)
	{
		if (temp->indice==nuevo->indice)//si son iguales sobrescribo
		{
			yaExisteDia = true;
		}
		else if (temp->siguiente != NULL) //si el siguiente es distinto de NULL sino cuando sea el ultimo tirara error
		{
			if (temp->siguiente->indice > nuevo->indice)//si el siguiente es mayor que el nuevo
			{
				bandera = true;
				break;
			}
			
		}
		if (temp->siguiente != NULL) //si el siguiente no es null avanza
		{
			temp = temp->siguiente;
		}
		else //si el siguiente es null, me saca del ciclo while
		{
			break;
		}
	}

	if (yaExisteDia==false) //si el dia aun no existe, lo agrega
	{
		if (bandera == true) //el siguiente es mayor que actual, entonces se inserta antes del siguiente
		{
			nuevo->siguiente = temp->siguiente;
			temp->siguiente = nuevo;
		}
		else //cuando bandera es false, temp es el ultimo, entonces el nuevo lo inserta despues
		{
			temp->siguiente = nuevo;
		}
	}

}

void insertarActividad(string _dia, string actividad)
{	
	if (_dia=="Lunes")
	{
		dias *nuevo = new dias(0, "Lunes"); //se crea un nodo tipo Dias
		dias *root = miRaiz; //nodo raiz
		insertarOrdenadoDia(nuevo, root); //se inserta dia
		enlazarActividad(0,actividad); //se inserta actividad

	}
	else if (_dia == "Martes")
	{
		dias *nuevo = new dias(1, "Martes");
		dias *root = miRaiz;
		insertarOrdenadoDia(nuevo, root);
		enlazarActividad(1, actividad);
	}
	else if (_dia == "Miercoles")
	{
		dias *nuevo = new dias(2, "Miercoles");
		dias *root = miRaiz;
		insertarOrdenadoDia(nuevo, root);
		enlazarActividad(2, actividad);
	}
	else if (_dia == "Jueves")
	{
		dias *nuevo = new dias(3, "Jueves");
		dias *root = miRaiz;
		insertarOrdenadoDia(nuevo, root);
		enlazarActividad(3, actividad);
	}
	else if (_dia == "Viernes")
	{
		dias *nuevo = new dias(4, "Viernes");
		dias *root = miRaiz;
		insertarOrdenadoDia(nuevo, root);
		enlazarActividad(4, actividad);
	}
	else if (_dia == "Sabado")
	{
		dias *nuevo = new dias(5, "Sabado");
		dias *root = miRaiz;
		insertarOrdenadoDia(nuevo, root);
		enlazarActividad(5, actividad);
	}
	else if (_dia == "Domingo")
	{
		dias *nuevo = new dias(6, "Domingo");
		dias *root = miRaiz;
		insertarOrdenadoDia(nuevo, root);
		enlazarActividad(6, actividad);
	}
	else{
		string imp = "\n ERROR EN INSERTAR, LA LETRA INICIAL DE CADA DIA DEBE SER CON MAYUSCULA \n";
		cout << imp << endl;
	}
}

void imprimirSemana()
{
	printf("\n ######################### TODA LA SEMANA ################################ \n\n");
	dias *aux = miRaiz->siguiente; //empezara en el siguiente de raiz

	if (aux!=NULL) //si hay dias entonces entra...
	{
		while (aux != NULL) //mientras sea distinto de null, sigue...
		{
			string d = "DIA ---> " + aux->dia;
			cout << d << endl; //imprime el dia correspondiente...

			actividades *auxA = aux->primeroA; //se crea un nodo actividad que sera la primera actividad de ese dia (primeroA)

			if (auxA != NULL) //si es distinto de null entra, o sea que si ese dia contiene una actividad
			{
				while (auxA!=NULL) //mientras sea distinto a null sigue... (mientras allan actividades)
				{
					string e = "  ACTIVIDAD ---> " + auxA->actividad; 
					cout << e << endl; //imprime actividad
					auxA = auxA->siguiente; //avanza a la siguiente actividad
				}

			}
			printf("\n");
			aux = aux->siguiente; //avanza al siguiente dia
		}
	}
	printf("######################################################################## \n");
		
}

bool buscarDia(string _dia)
{
	dias *aux = miRaiz->siguiente;
	bool bandera = false;

	if (aux!=NULL)
	{
		while (aux!=NULL)
		{
			if (_dia == aux->dia)
			{
				bandera = true; //si lo encuentra retornara true
			}
			aux = aux->siguiente;
		}
	}
	return bandera;
}

void imprimirDia(string _dia)
{
	printf("\n ######################### DIA ESPECIFICO ################################ \n\n");
	dias *aux = miRaiz->siguiente;
	bool bandera = false;

	while (aux!=NULL)
	{
		if (_dia==aux->dia)//encuentra el dia
		{
			string d = "DIA ESPECIFICO ---> " + aux->dia;
			cout << d << endl; //imprime el dia correspondiente...

			actividades *auxA = aux->primeroA;

			if (auxA != NULL)
			{
				while (auxA != NULL)
				{
					string e = "  ACTIVIDAD ---> " + auxA->actividad;
					cout << e << endl; //imprime actividad
					auxA = auxA->siguiente;
				}				
			}
			bandera = true; //ya encontro dia, se vuelve true
		}

		if (bandera == true) //si bandera es true, saca del ciclo
		{
			break;
		}

		aux = aux->siguiente;
	}
	printf("\n ######################################################################## \n");
}


void imprimirDiaEspecifico(string _dia)
{
	if (_dia == "Lunes")
	{		
		if (buscarDia(_dia)==true)//si encuentra el dia...
		{
			imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Martes")
	{
		if (buscarDia(_dia) == true)
		{
			imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Miercoles")
	{
		if (buscarDia(_dia) == true)
		{
			imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Jueves")
	{
		if (buscarDia(_dia) == true)
		{
			imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Viernes")
	{
		if (buscarDia(_dia) == true)
		{
			imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Sabado")
	{
		if (buscarDia(_dia) == true)
		{
			imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Domingo")
	{
		if (buscarDia(_dia) == true)
		{
			imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else{
		string imp = "ERROR, LA LETRA INICIAL DE CADA DIA DEBE SER CON MAYUSCULA \n";
		cout << imp << endl;
	}
}

void opciones(int op)
{
	string insertDia = "";
	string insertAct = "";
	string ingdia = "";

	switch (op)
	{
	case 1:
		printf("\n INGRESAR DIA: \n");
		cin >> insertDia;
		printf("\n INGRESAR ACTIVIDAD: \n");
		cin >> insertAct;
		insertarActividad(insertDia,insertAct);
		break;
	case 2:
		imprimirSemana();
		break;
	case 3:		
		printf("\n INGRESE DIA: \n");
		cin >> ingdia;
		imprimirDiaEspecifico(ingdia);
		break;
	case 4:		
		exit(0);
	default:
		printf("\n OPCION INVALIDA \n");
		break;
	}
}

void menu()
{
	int opcion;
	do{
		printf(" \n -------MENU------ \n");
		printf("1. Insertar Actividad \n");
		printf("2. Imprimir Actividades de toda la Semana \n");
		printf("3. Imprimir Actividades de un Dia especifico \n");
		printf("4. Salir \n");

		printf("\n ELIJA UNA OPCION: \n");
		cin >> opcion;
		opciones(opcion);
	} while (true);
	
}

int main(){

	insertarNodoRaiz();
	
	menu();

	return 0;
}