#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class nodoProducto{
public:
	nodoProducto *siguiente;
	nodoProducto *anterior;
	int codProducto;
	int stock;
	int stockminimo;
	string codProvee;
	nodoProducto(int,int,int,string);
};

nodoProducto::nodoProducto(int codp, int stockk, int stockm, string codpre)
{
	this->siguiente = NULL;
	this->codProducto = codp;
	this->stock = stockk;
	this->stockminimo = stockm;
	this->codProvee = codpre;
}

class productos{
public:
	nodoProducto *raiz;
	productos();
	void insertarOrdenado(int,int,int,string);
	void eliminar();
	void imprimir();
};

productos::productos()
{
	this->raiz = new nodoProducto(-1,-1,-1,"raiz");
}

void productos::insertarOrdenado(int codprod, int stock,int stockmin, string codProvee )
{
	nodoProducto *nuevo = new nodoProducto(codprod,stock,stockmin,codProvee);
	nodoProducto *temp = this->raiz;
	bool bandera = false;

	while (true)
	{
		if (temp->siguiente != NULL)
		{
			if (temp->siguiente->codProducto<codprod)
			{
				bandera = true;
				break;
			}
		}
		if (temp->siguiente != NULL)
		{
			temp = temp->siguiente;
		}
		else{
			break;
		}
	}

	if (bandera == true)
	{
		//si el siguiente es menor, lo inserto antes
		nuevo->siguiente = temp->siguiente;
		temp->siguiente->anterior = nuevo;
		temp->siguiente = nuevo;
		nuevo->anterior = temp;
	}
	else{
		//lo inserto de ultimo
		temp->siguiente = nuevo;
		nuevo->anterior = temp;
	}

	

}

void productos::imprimir()
{
	nodoProducto *aux = this->raiz->siguiente;

	if (aux!=NULL)
	{
		while (aux != NULL)
		{
			cout << "Cod. Producto: " << aux->codProducto << " Stock: " << aux->stock << " Stock Min: " << aux->stockminimo << " Cod. Prov: " << aux->codProvee << endl;
			aux = aux->siguiente;
		}
	}
	
}

void productos::eliminar()
{
	nodoProducto *aux = this->raiz->siguiente;

	if (aux != NULL)
	{
		while (aux != NULL)
		{			
			if (aux->codProducto>100)
			{
				aux->anterior->siguiente = aux->siguiente;
				aux->siguiente->anterior = aux->anterior;
			}
			aux = aux->siguiente;
		}
	}
}

productos product; //instancia principal

void copiarLista()
{
	productos productNueva;

	nodoProducto *temp = product.raiz->siguiente;

	while (temp!=NULL)
	{
		if (temp->stock<temp->stockminimo)
		{
			productNueva.insertarOrdenado(temp->codProducto,temp->stock,temp->stockminimo,temp->codProvee);
		}
		temp = temp->siguiente;
	}

	printf("\n--> COPIA DE LISTA\n");
	productNueva.imprimir();
}

int main()
{
	product.insertarOrdenado(130,9,15,"a1a2a3");
	product.insertarOrdenado(9, 8, 3, "b1b2b3");
	product.insertarOrdenado(2, 8, 12, "c1c2c3");
	product.insertarOrdenado(200, 9, 8, "d1d2d3");
	product.insertarOrdenado(5, 12,32, "e1e2e3");
	product.insertarOrdenado(7, 14, 20, "f1f2f3");
	product.insertarOrdenado(230, 20, 10, "g1g2g3");
	product.insertarOrdenado(21, 5, 9, "h1h2h3");
	product.insertarOrdenado(101, 2, 40, "i1i2i3");
	product.insertarOrdenado(1, 120, 200, "j1j2j3");
	product.insertarOrdenado(125, 7, 50, "k1k2k3");
	product.imprimir();
	copiarLista();
	printf("\nLISTA CON DATOS ELIMINADOS:\n");
	product.eliminar();
	product.imprimir();
	system("pause");
	return 0;
}