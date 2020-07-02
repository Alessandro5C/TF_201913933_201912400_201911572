#pragma once
#include "CArbol.h"
#include <functional>
#include <iomanip>
#include <fstream>
#include <map>
class CTabla
{
protected:
	map<string, CCols*> mapcols;
	map<string, CArbol*> arboles;

public:
	class CFila
	{
		int idx;
		CTabla* tabla;
	public:
		CFila(int idx, CTabla* tabla)
			: idx(idx), tabla(tabla) {}
		CFila(CTabla* tabla) : tabla(tabla) {}
		~CFila() {}

		CTabla* getTabla() { return tabla; } //Añadido

		int getidx() { return idx; }

		void add(string nombre, string dato) { tabla->mapcols[nombre]->addDato(dato); }
		//aqui
		void get(int i)
		{
			for (auto col : tabla->mapcols)
				cout << setw(15) << col.second->getDato(i);
			cout << endl;
		}
		//variacion
		void get() {
			for (auto col : tabla->mapcols)
				cout << setw(15) << col.second->getDato(idx);
			cout << endl;
			/*         col.second->getDato(idx);           */
		}
		void get(int i, string name_last_col) {
			for (auto col : tabla->mapcols) {
				cout << col.second->getDato(i);
				//(e.first == name_last_col) ? arch << "\n" : arch << ";";
			}
		}
		//aqui

		void cambiar(int i, int j)
		{
			for (auto col : tabla->mapcols)
			{
				
				auto aux = col.second->getDato(i);
				auto aux2 = col.second->getDato(j);

				col.second->setDato(j, aux);
				col.second->setDato(i, aux2);
			}
		}
		//variacion
		void cambiar(int j) {
			for (auto col : tabla->mapcols) {
				auto aux1 = col.second->getDato(idx); 
				auto aux2 = col.second->getDato(j);
				col.second->setDato(j, aux1); 
				col.second->setDato(idx, aux2);
			}
		}

		string getdato(string nombre_col) { return tabla->mapcols[nombre_col]->getDato(idx); }
	};

private:
	int f, c;
	map<int, CFila*> maprows;

public:
	CTabla() : f(0), c(0) {}
	~CTabla() {} 

	int getNcols() { return c; }
	int getNfilas() { return f; }

	void addCol(CCols* new_col) { 
		mapcols[new_col->getName()] = new_col; 
		c++;
	}

	CFila* addFila() {
		CFila* aux = 
			new CFila(f, this);
		maprows[f++] = aux; //f++;
		return aux;
	}

	CCols* getCol(string name_col) { return mapcols[name_col]; }
	CFila* getFila(int nfila) { return maprows[nfila]; }

	void swapFilas(int i, int j) {
		CFila* aux = maprows[i];
		maprows[i] = maprows[j];
		maprows[j] = aux; delete aux; //nose si el indice idx en la clase fila tamb sea necesario  cambiar
	}

	//aqui
	void mostrar()
	{
		for (auto i : mapcols)
			cout << setw(15) << i.first;
		cout << endl;
		for (int i = 0; i < f; i++)
		{
			maprows[i]->get(i);
		}

	}

	void saveOnArch(string auxs, string name_last_col) {
		std::ofstream arch(auxs);
		if (arch.is_open() == NULL) { return; }
		//Escribe el tipo de las columnas
		for (auto e : mapcols) {
			arch << e.second->getType();
			(e.first == name_last_col) ? arch << "\n" : arch << ";";
		}
		//Escribe el nombre de las columnas
		for (auto e : mapcols) {
			arch << e.first;
			( e.first == name_last_col) ? arch << "\n" : arch << ";";
		}
		//Escribe los datos de las columnas por filas
		for (auto fila : maprows) {
			for (auto e : mapcols) {
				arch << e.second->getDato(fila.first);
				(e.first == name_last_col) ? arch << "\n" : arch << ";";
			}
		} arch.close();
	}

	//aqui
	void ordenar(string colu, function<bool(string, string)>&lam)
	{
		vector<string>aux = mapcols[colu]->getAllData();

		for (int i = 0; i < aux.size(); i++)
		{
			for (int j = i + 1; j < aux.size(); j++)
			{
				if (lam(aux[i], aux[j]))
				{
					maprows[0]->cambiar(i, j);
					aux = mapcols[colu]->getAllData();
				}
			}
		}
	};

	//aqui
	void filtrar(string colu, string cmp, function<bool(string, string, string)>&lam)
	{
		cout << "Los resultados del filtrado son:\n";
		for (int i = 0; i < f; i++)
		{
			if (lam(mapcols[colu]->getDato(i), cmp, mapcols[colu]->getType()))
				maprows[i]->get(i);
		}
	}
	void filtrar(string colu, string cmp, function<bool(string, string, string)>&lam, 
		string colu2, string cmp2, function<bool(string, string, string)>&lam2)
	{
		cout << "Los resultados del filtrado son:\n";
		for (int i = 0; i < f; i++)
		{
			if (lam(mapcols[colu]->getDato(i), cmp, mapcols[colu]->getType()) 
				&& lam2(mapcols[colu2]->getDato(i), cmp2, mapcols[colu2]->getType()))
				maprows[i]->get(i);
		}
	}
	//variacion
	void filtrar(string nombre_col, string s_cmp, function<bool(string, string)>&lambda, CTabla* taux) {
		CCols* aux_col;
		for (auto e : mapcols) {
			aux_col = new CCols(e.first, e.second->getType());
			taux->addCol(aux_col);
		}

		for (auto e: taux->mapcols)
		{
			cout << e.first << "\t";
		}
		//las columnas deben ser igual para los dos, this and grup
		//osea deben haber sido creadas antes
		CFila* aux_fila;
		for (int i = 0; i < f; i++)	{
			if (lambda(mapcols[nombre_col]->getDato(i), s_cmp)) {
				aux_fila = taux->addFila();
				for (auto e : mapcols/*tabla->mapcols*/) {
					aux_fila->add(e.first, e.second->getDato(i));
				}
			}
		}

	}

	void indexar(string nombre_cols)
	{
		CArbol*nuevo = new CArbol();
		arboles[nombre_cols] = nuevo;

		vector<string>aux = mapcols[nombre_cols]->getAllData();

		for (int i = 0; i < f; i++)
		{
			nuevo->add(aux[i], i);
		}


	}
	void buscar(string nombre_col, string dato)
	{
		int existe = arboles.count(nombre_col);
		cout << "Los resultados de la búsqueda:\t";
		if (existe == 1)
		{
			// Buscar en el árbol
			//en arbol
			cout << "en un BST AVL:\n";
			vector<int>pos = arboles[nombre_col]->find(dato);

			for (int i = 0; i < pos.size(); i++)
			{
				maprows[pos[i]]->get(pos[i]);
			}
		}
		else
		{
			// Buscar en la columna; 
			//secuencial
			cout << "secuencial:\n";
			for (int i = 0; i < f; i++)
			{
				if (mapcols[nombre_col]->findDato(i, dato))
					maprows[i]->get(i);
			}
		}
	}
	void inorder(string nombre_col)
	{
		arboles[nombre_col]->inorder();
	}
};