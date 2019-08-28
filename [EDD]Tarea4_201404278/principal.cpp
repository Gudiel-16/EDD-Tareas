#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void opciones(int);
void insertarActividad(string, int, string);
void menu();
void imprimirDiaEspecifico(string);

///////////////////////////////////////////////////////// CLASE NODO MATRIZ ///////////////////////////////////////////////////////////////////

class nodoMatriz
{
public:
	nodoMatriz *raiz;
	nodoMatriz *siguiente;
	nodoMatriz *anterior;
	nodoMatriz *abajo;
	nodoMatriz *arriba;
	int x;
	int y;
	string actividad;
	string dia;
	nodoMatriz(int, int, string,string); //constructor
};

nodoMatriz::nodoMatriz(int _x, int _y, string _actividad, string _dia) //constructor
{
	this->siguiente = NULL;
	this->anterior = NULL;
	this->abajo = NULL;
	this->arriba = NULL;
	this->x = _x;
	this->y = _y;
	this->actividad = _actividad;
	this->dia = _dia;
}


///////////////////////////////////////////////////////// CLASE MATRIZ ///////////////////////////////////////////////////////////////////

class Matriz
{
public:
	nodoMatriz *raiz; //raiz de mi matriz	
	bool buscarfila(int);
	bool buscarColumna(int);
	nodoMatriz insertarOrdenadoColumna(nodoMatriz, nodoMatriz);
	nodoMatriz insertarOrdenadoFila(nodoMatriz, nodoMatriz);
	nodoMatriz crearColumna(int);
	nodoMatriz crearFila(int);
	void imprimirSemana();
	void imprimirDia(string);
	void imprimirDiaEspecifico(string);
	bool buscarDia(string);
	Matriz(); //constructor
	void insertarElemento(int, int, string, string);
};

Matriz::Matriz()
{
	this->raiz = new nodoMatriz(-1, -1, "raiz", "rDia"); //inicializamos creando raiz

}

void Matriz::insertarElemento(int _x, int _y, string actividad, string dia)
{
	nodoMatriz *nuevo = new nodoMatriz(_x, _y, actividad, dia);
	nodoMatriz *nodoColumn = NULL;
	nodoMatriz *nodoFila = NULL;

	//BUSCAR FILA
	int banderaBuscarFila = 0;
	nodoMatriz *tempBuscarFila = this->raiz;
	while (tempBuscarFila != NULL)
	{
		if (tempBuscarFila->y == _y)
		{
			banderaBuscarFila = 1;
		}
		tempBuscarFila = tempBuscarFila->abajo;
	}

	//BUSCAR COLUMNA
	int banderaBuscarColumn = 0;
	nodoMatriz *tempBuscarColumn = this->raiz;
	while (tempBuscarColumn != NULL)
	{
		if (tempBuscarColumn->x == _x)
		{
			banderaBuscarColumn = 1;
		}
		tempBuscarColumn = tempBuscarColumn->siguiente;
	}

	int Nodcolumna = banderaBuscarColumn;
	int Nodfila = banderaBuscarFila;

	// 1 CASO: COLUMNA NO EXISTA Y FILA NO EXISTA
	if (Nodcolumna == 0 && Nodfila == 0)
	{
		// SE CREA COLUMNA
		nodoMatriz *temp1 = this->raiz;
		nodoMatriz *nuevo2 = new nodoMatriz(_x, -1, "COL", dia);
		bool bandeColum = false;
		bool bandeColumIguales = false;
		while (true)
		{
			if (temp1->x == nuevo2->x) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				temp1->y = nuevo2->y;
				temp1->actividad = nuevo2->actividad;
				bandeColumIguales = true;
				break;
			}
			else if (temp1->x > nuevo2->x){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeColum = true;
				break;
			}
			if (temp1->siguiente != NULL)
			{
				temp1 = temp1->siguiente;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeColum == true) // INSERTARLO ANTES DE TEMPORAL
		{
			nuevo2->siguiente = temp1;
			temp1->anterior->siguiente = nuevo2;
			nuevo2->anterior = temp1->anterior;
			temp1->anterior = nuevo2;
		}
		else{
			temp1->siguiente = nuevo2;
			nuevo2->anterior = temp1;
		}

		if (bandeColumIguales == true)
		{
			nodoColumn = temp1;;
		}
		else{
			nodoColumn = nuevo2;
		}

		//SE CREA FILA
		nodoMatriz *temp2 = this->raiz;
		nodoMatriz *nuevo3 = new nodoMatriz(-1, _y, "FIL", "rDia");
		bool bandeFil = false;
		bool bandeFilIguales = false;

		while (true)
		{
			if (temp2->y == nuevo3->y) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				temp2->x = nuevo3->x;
				temp2->actividad = nuevo3->actividad;
				bandeFilIguales = true;
				break;
			}
			else if (temp2->y > nuevo3->y){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeFil = true;
				break;
			}
			if (temp2->abajo != NULL)
			{
				temp2 = temp2->abajo;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeFil == true) // INSERTARLO ANTES DE TEMPORAL
		{
			nuevo3->abajo = temp2;
			temp2->arriba->abajo = nuevo3;
			nuevo3->arriba = temp2->arriba;
			temp2->arriba = nuevo3;
		}
		else{
			temp2->abajo = nuevo3;
			nuevo3->arriba = temp2;
		}

		if (bandeFilIguales == true)
		{
			nodoFila = temp2;
		}
		else{
			nodoFila = nuevo3;
		}


		//INSERTAMOS NODO DE FORMA ORDENADA EN COLUMNA (nuevo, nodoFila) //temp=nodoFila
		bandeColum = false;
		bandeColumIguales = false;
		while (true)
		{
			if (nodoFila->x == nuevo->x) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				nodoFila->y = nuevo->y;
				nodoFila->actividad = nuevo->actividad;
				bandeColumIguales = true;
				break;
			}
			else if (nodoFila->x > nuevo->x){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeColum = true;
				break;
			}
			if (nodoFila->siguiente != NULL)
			{
				nodoFila = nodoFila->siguiente;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeColum == true) // INSERTARLO ANTES DE TEMPORAL
		{
			nuevo->siguiente = nodoFila;
			nodoFila->anterior->siguiente = nuevo;
			nuevo->anterior = nodoFila->anterior;
			nodoFila->anterior = nuevo;
		}
		else{
			nodoFila->siguiente = nuevo;
			nuevo->anterior = nodoFila;
		}


		//INSERTAMOS NODO DE FORMA ORDENADA EN FILA (nuevo, nodoColumna) //temp=nodoColumna
		bandeFil = false;
		bandeFilIguales = false;

		while (true)
		{
			if (nodoColumn->y == nuevo->y) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				nodoColumn->x = nuevo->x;
				nodoColumn->actividad = nuevo->actividad;
				bandeFilIguales = true;
				break;
			}
			else if (nodoColumn->y > nuevo->y){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeFil = true;
				break;
			}
			if (nodoColumn->abajo != NULL)
			{
				nodoColumn = nodoColumn->abajo;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeFil == true) // INSERTARLO ANTES DE TEMPORAL
		{
			nuevo->abajo = nodoColumn;
			nodoColumn->arriba->abajo = nuevo;
			nuevo->arriba = nodoColumn->arriba;
			nodoColumn->arriba = nuevo;
		}
		else{
			nodoColumn->abajo = nuevo;
			nuevo->arriba = nodoColumn;
		}

	}
	else if (Nodcolumna == 0 && Nodfila == 1){ // 2 CASO: COLUNMA NO EXISTA Y FILA EXISTA

		// SE CREA COLUMNA
		nodoMatriz *temp1 = this->raiz;
		nodoMatriz *nuevo2 = new nodoMatriz(_x, -1, "COL", dia);
		bool bandeColum = false;
		bool bandeColumIguales = false;
		while (true)
		{
			if (temp1->x == nuevo2->x) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				temp1->y = nuevo2->y;
				temp1->actividad = nuevo2->actividad;
				bandeColumIguales = true;
				break;
			}
			else if (temp1->x > nuevo2->x){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeColum = true;
				break;
			}
			if (temp1->siguiente != NULL)
			{
				temp1 = temp1->siguiente;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeColum == true) // INSERTARLO ANTES DE TEMPORAL
		{
			nuevo2->siguiente = temp1;
			temp1->anterior->siguiente = nuevo2;
			nuevo2->anterior = temp1->anterior;
			temp1->anterior = nuevo2;
		}
		else{
			temp1->siguiente = nuevo2;
			nuevo2->anterior = temp1;
		}

		if (bandeColumIguales == true)
		{
			nodoColumn = temp1;;
		}
		else{
			nodoColumn = nuevo2;
		}

		//SE CREA FILA
		nodoMatriz *temp2 = this->raiz;
		nodoMatriz *nuevo3 = new nodoMatriz(-1, _y, "FIL", "rDia");
		bool bandeFil = false;
		bool bandeFilIguales = false;

		while (true)
		{
			if (temp2->y == nuevo3->y) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				temp2->x = nuevo3->x;
				temp2->actividad = nuevo3->actividad;
				bandeFilIguales = true;
				break;
			}
			else if (temp2->y > nuevo3->y){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeFil = true;
				break;
			}
			if (temp2->abajo != NULL)
			{
				temp2 = temp2->abajo;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeFilIguales == true)
		{
			nodoFila = temp2;
		}
		else{
			nodoFila = nuevo3;
		}


		//INSERTAMOS NODO DE FORMA ORDENADA EN COLUMNA (nuevo, nodoFila) //temp=nodoFila
		bandeColum = false;
		bandeColumIguales = false;
		while (true)
		{
			if (nodoFila->x == nuevo->x) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				nodoFila->y = nuevo->y;
				nodoFila->actividad = nuevo->actividad;
				bandeColumIguales = true;
				break;
			}
			else if (nodoFila->x > nuevo->x){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeColum = true;
				break;
			}
			if (nodoFila->siguiente != NULL)
			{
				nodoFila = nodoFila->siguiente;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeColum == true) // INSERTARLO ANTES DE TEMPORAL
		{
			nuevo->siguiente = nodoFila;
			nodoFila->anterior->siguiente = nuevo;
			nuevo->anterior = nodoFila->anterior;
			nodoFila->anterior = nuevo;
		}
		else{
			nodoFila->siguiente = nuevo;
			nuevo->anterior = nodoFila;
		}


		//INSERTAMOS NODO DE FORMA ORDENADA EN FILA (nuevo, nodoColumna) //temp=nodoColumna
		bandeFil = false;
		bandeFilIguales = false;

		while (true)
		{
			if (nodoColumn->y == nuevo->y) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				nodoColumn->x = nuevo->x;
				nodoColumn->actividad = nuevo->actividad;
				bandeFilIguales = true;
				break;
			}
			else if (nodoColumn->y > nuevo->y){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeFil = true;
				break;
			}
			if (nodoColumn->abajo != NULL)
			{
				nodoColumn = nodoColumn->abajo;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeFil == true) // INSERTARLO ANTES DE TEMPORAL
		{
			nuevo->abajo = nodoColumn;
			nodoColumn->arriba->abajo = nuevo;
			nuevo->arriba = nodoColumn->arriba;
			nodoColumn->arriba = nuevo;
		}
		else{
			nodoColumn->abajo = nuevo;
			nuevo->arriba = nodoColumn;
		}

	}
	else if (Nodcolumna == 1 && Nodfila == 0){ // 3 CASO: COLUMNA EXISTA Y LA FILA NO EXISTA

		// SE CREA COLUMNA
		nodoMatriz *temp1 = this->raiz;
		nodoMatriz *nuevo2 = new nodoMatriz(_x, -1, "COL", dia);
		bool bandeColum = false;
		bool bandeColumIguales = false;
		while (true)
		{
			if (temp1->x == nuevo2->x) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				temp1->y = nuevo2->y;
				temp1->actividad = nuevo2->actividad;
				bandeColumIguales = true;
				break;
			}
			else if (temp1->x > nuevo2->x){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeColum = true;
				break;
			}
			if (temp1->siguiente != NULL)
			{
				temp1 = temp1->siguiente;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeColumIguales == true)
		{
			nodoColumn = temp1;;
		}
		else{
			nodoColumn = nuevo2;
		}

		//SE CREA FILA
		nodoMatriz *temp2 = this->raiz;
		nodoMatriz *nuevo3 = new nodoMatriz(-1, _y, "FIL", "rDia");
		bool bandeFil = false;
		bool bandeFilIguales = false;

		while (true)
		{
			if (temp2->y == nuevo3->y) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				temp2->x = nuevo3->x;
				temp2->actividad = nuevo3->actividad;
				bandeFilIguales = true;
				break;
			}
			else if (temp2->y > nuevo3->y){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeFil = true;
				break;
			}
			if (temp2->abajo != NULL)
			{
				temp2 = temp2->abajo;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeFil == true) // INSERTARLO ANTES DE TEMPORAL
		{
			nuevo3->abajo = temp2;
			temp2->arriba->abajo = nuevo3;
			nuevo3->arriba = temp2->arriba;
			temp2->arriba = nuevo3;
		}
		else{
			temp2->abajo = nuevo3;
			nuevo3->arriba = temp2;
		}

		if (bandeFilIguales == true)
		{
			nodoFila = temp2;
		}
		else{
			nodoFila = nuevo3;
		}


		//INSERTAMOS NODO DE FORMA ORDENADA EN COLUMNA (nuevo, nodoFila) //temp=nodoFila
		bandeColum = false;
		bandeColumIguales = false;
		while (true)
		{
			if (nodoFila->x == nuevo->x) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				nodoFila->y = nuevo->y;
				nodoFila->actividad = nuevo->actividad;
				bandeColumIguales = true;
				break;
			}
			else if (nodoFila->x > nuevo->x){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeColum = true;
				break;
			}
			if (nodoFila->siguiente != NULL)
			{
				nodoFila = nodoFila->siguiente;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeColum == true) // INSERTARLO ANTES DE TEMPORAL
		{
			nuevo->siguiente = nodoFila;
			nodoFila->anterior->siguiente = nuevo;
			nuevo->anterior = nodoFila->anterior;
			nodoFila->anterior = nuevo;
		}
		else{
			nodoFila->siguiente = nuevo;
			nuevo->anterior = nodoFila;
		}


		//INSERTAMOS NODO DE FORMA ORDENADA EN FILA (nuevo, nodoColumna) //temp=nodoColumna
		bandeFil = false;
		bandeFilIguales = false;

		while (true)
		{
			if (nodoColumn->y == nuevo->y) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				nodoColumn->x = nuevo->x;
				nodoColumn->actividad = nuevo->actividad;
				bandeFilIguales = true;
				break;
			}
			else if (nodoColumn->y > nuevo->y){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeFil = true;
				break;
			}
			if (nodoColumn->abajo != NULL)
			{
				nodoColumn = nodoColumn->abajo;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		if (bandeFil == true) // INSERTARLO ANTES DE TEMPORAL
		{
			nuevo->abajo = nodoColumn;
			nodoColumn->arriba->abajo = nuevo;
			nuevo->arriba = nodoColumn->arriba;
			nodoColumn->arriba = nuevo;
		}
		else{
			nodoColumn->abajo = nuevo;
			nuevo->arriba = nodoColumn;
		}

	}
	else if (Nodcolumna == 1 && Nodfila == 1){ // 4 CASO: COLUMNA Y LA FILA EXISTEN

		bool bandeColum = false;
		bool bandeFil = false;

		//BUSCAR FILA
		nodoMatriz *BuscarFila = this->raiz;
		nodoMatriz *filaa = NULL;
		while (BuscarFila != NULL)
		{
			if (BuscarFila->y == _y)
			{
				filaa = BuscarFila;
				break;
			}
			BuscarFila = BuscarFila->abajo;
		}

		//BUSCAR COLUMNA
		nodoMatriz *BuscarColumn = this->raiz;
		nodoMatriz *columnaa = NULL;
		while (BuscarColumn != NULL)
		{
			if (BuscarColumn->x == _x)
			{
				columnaa = BuscarColumn;
				break;
			}
			BuscarColumn = BuscarColumn->siguiente;
		}

		//INSERTAMOS NODO DE FORMA ORDENADA EN COLUMNA (nuevo, nodoFila) //temp=nodoFila

		bandeColum = false;
		while (true)
		{
			if (filaa->x == nuevo->x) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				filaa->y = nuevo->y;
				filaa->actividad = nuevo->actividad;
				break;
			}
			else if (filaa->x > nuevo->x){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeColum = true;
				break;
			}
			if (filaa->siguiente != NULL)
			{
				filaa = filaa->siguiente;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}


		//INSERTAMOS NODO DE FORMA ORDENADA EN FILA (nuevo, nodoColumna) //temp=nodoColumna

		bandeFil = false;

		while (true)
		{
			if (columnaa->y == nuevo->y) // SI LA POSICION ES LA MISMA SOBRE ESCRIBO
			{
				columnaa->x = nuevo->x;
				columnaa->actividad = nuevo->actividad;
				break;
			}
			else if (columnaa->y > nuevo->y){ // TENGO QUE INSERTARLO ANTES DE TEMP
				bandeFil = true;
				break;
			}
			if (columnaa->abajo != NULL)
			{
				columnaa = columnaa->abajo;
			}
			else{ // TENGO QUE INSERTAR NUEVO DESPUES DE TEMP, Y BANDECOLUM SERA FALSE
				break;
			}
		}

		//BUSCAR SI YA EXISTE ESA COORDENADA PARA AGREGARLO O NO
		nodoMatriz *buscarcoor = this->raiz;
		bool BuscarCoordenada = false;
		while (buscarcoor != NULL)
		{
			nodoMatriz *buscarcoor2 = buscarcoor->siguiente;
			while (buscarcoor2 != NULL)
			{
				if (buscarcoor2->x == _x && buscarcoor2->y == _y)
				{
					BuscarCoordenada = true;
					break;
				}

				buscarcoor2 = buscarcoor2->siguiente;
			}

			buscarcoor = buscarcoor->abajo;
		}

		if (BuscarCoordenada == false) // SI AUN NO EXISTE LA COORDENADA AGREGA EL NODO
		{
			if (bandeColum == true) // INSERTARLO ANTES DE TEMPORAL
			{
				nuevo->siguiente = filaa;
				filaa->anterior->siguiente = nuevo;
				nuevo->anterior = filaa->anterior;
				filaa->anterior = nuevo;
			}
			else{
				filaa->siguiente = nuevo;
				nuevo->anterior = filaa;
			}

			if (bandeFil == true) // INSERTARLO ANTES DE TEMPORAL
			{
				nuevo->abajo = columnaa;
				columnaa->arriba->abajo = nuevo;
				nuevo->arriba = columnaa->arriba;
				columnaa->arriba = nuevo;
			}
			else{
				columnaa->abajo = nuevo;
				nuevo->arriba = columnaa;
			}
		}

	}
}

void Matriz::imprimirSemana()
{
	nodoMatriz *temp = this->raiz->siguiente;
	string filas = "";

	if (temp!=NULL)
	{
		printf("\n####################################################################### \n\n");

		while (temp!=NULL)
		{
			cout << "--> Dia: " << temp-> dia << "\n" << endl;
			nodoMatriz *aux = temp->abajo;
			if (aux!=NULL)
			{
				while (aux!=NULL)
				{
					cout << "    HORA: " << aux->y << " , " << " ACTIVIDAD: " << aux->actividad << endl;

					aux = aux->abajo;
				}				
			}
			printf("\n");
			temp = temp->siguiente;
		}
	}

	printf("\n####################################################################### \n\n");



}

bool Matriz::buscarDia(string _dia)
{
	nodoMatriz *aux = this->raiz->siguiente;
	bool bandera = false;

	if (aux != NULL)
	{
		while (aux != NULL)
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

void Matriz::imprimirDia(string _dia)
{
	nodoMatriz *aux = this->raiz->siguiente;
	bool bandera = false;

	if (aux != NULL)
	{
		printf("\n####################################################################### \n\n");

		while (aux != NULL)
		{
			if (_dia == aux->dia)//encuentra el dia
			{
				cout << "--> Dia: " << aux->dia << "\n" << endl;
				nodoMatriz *temp = aux->abajo;

				if (temp != NULL)
				{
					while (temp != NULL)
					{
						cout << "    HORA: " << temp->y << " , " << " ACTIVIDAD: " << temp->actividad << endl;
						temp = temp->abajo;
					}
				}
				bandera = true; //ya encontro dia
			}

			if (bandera == true) //si bandera es true, saca del ciclo
			{
				break;
			}

			aux = aux->siguiente;
		}

	}

	printf("\n####################################################################### \n\n");

}

Matriz objMatriz; // variable global pra asi poder insertar en la matriz

int main()
{
	menu();
	system("pause");
	return 0;
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

void opciones(int op)
{
	string insertDia = "";
	string insertAct = "";
	string inserthor = "";
	string ingdia = "";

	switch (op)
	{
	case 1:
		printf("\n INGRESAR DIA: \n");
		cin >> insertDia;
		printf("\n INGRESAR HORA: \n");
		cin >> inserthor;
		printf("\n INGRESAR ACTIVIDAD: \n");
		cin >> insertAct;
		if ((inserthor.compare("1") == 0) || (inserthor.compare("2") == 0) || (inserthor.compare("3") == 0) || (inserthor.compare("4") == 0) 
			|| (inserthor.compare("5") == 0) || (inserthor.compare("6") == 0) || (inserthor.compare("7") == 0) || (inserthor.compare("8") == 0)
			|| (inserthor.compare("9") == 0) || (inserthor.compare("10") == 0) || (inserthor.compare("11") == 0) || (inserthor.compare("12") == 0)
			|| (inserthor.compare("13") == 0) || (inserthor.compare("14") == 0) || (inserthor.compare("15") == 0) || (inserthor.compare("16") == 0)
			|| (inserthor.compare("17") == 0) || (inserthor.compare("18") == 0) || (inserthor.compare("19") == 0) || (inserthor.compare("20") == 0)
			|| (inserthor.compare("21") == 0) || (inserthor.compare("22") == 0) || (inserthor.compare("23") == 0) || (inserthor.compare("24") == 0))  
		{
			int a = atoi(inserthor.c_str());
			insertarActividad(insertDia, a, insertAct);	
		}
		else{
			string imp = "\n ERROR EN INSERTAR HORA \n";
			cout << imp << endl;
		}
		break;
	case 2:
		objMatriz.imprimirSemana();
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

void insertarActividad(string _dia, int _hora, string actividad)
{
	if (_dia == "Lunes")
	{
		objMatriz.insertarElemento(0,_hora,actividad,"Lunes");

	}
	else if (_dia == "Martes")
	{
		objMatriz.insertarElemento(1, _hora, actividad, "Martes");
	}
	else if (_dia == "Miercoles")
	{
		objMatriz.insertarElemento(2, _hora, actividad,"Miercoles");
	}
	else if (_dia == "Jueves")
	{
		objMatriz.insertarElemento(3, _hora, actividad,"Jueves");
	}
	else if (_dia == "Viernes")
	{
		objMatriz.insertarElemento(4, _hora, actividad,"Viernes");
	}
	else if (_dia == "Sabado")
	{
		objMatriz.insertarElemento(5, _hora, actividad,"Sabado");
	}
	else if (_dia == "Domingo")
	{
		objMatriz.insertarElemento(6, _hora, actividad, "Domingo");
	}
	else{
		string imp = "\n ERROR EN INSERTAR, LA LETRA INICIAL DE CADA DIA DEBE SER CON MAYUSCULA \n";
		cout << imp << endl;
	}
}

void imprimirDiaEspecifico(string _dia)
{
	if (_dia == "Lunes")
	{
		if (objMatriz.buscarDia(_dia) == true)//si encuentra el dia...
		{
			objMatriz.imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Martes")
	{
		if (objMatriz.buscarDia(_dia) == true)
		{
			objMatriz.imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Miercoles")
	{
		if (objMatriz.buscarDia(_dia) == true)
		{
			objMatriz.imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Jueves")
	{
		if (objMatriz.buscarDia(_dia) == true)
		{
			objMatriz.imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Viernes")
	{
		if (objMatriz.buscarDia(_dia) == true)
		{
			objMatriz.imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Sabado")
	{
		if (objMatriz.buscarDia(_dia) == true)
		{
			objMatriz.imprimirDia(_dia);
		}
		else
		{
			printf("NO SE HA ENCONTRADO EL DIA ESPECIFICO! \n");
		}
	}
	else if (_dia == "Domingo")
	{
		if (objMatriz.buscarDia(_dia) == true)
		{
			objMatriz.imprimirDia(_dia);
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