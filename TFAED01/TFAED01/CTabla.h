#pragma once
#include "CCols.h"
#include "CArbol.h"
#include "CSVRow.h"
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

		CTabla* getTabla() { return tabla; }

		int getidx() { return idx; }

		void add(string nombre, string dato) { tabla->mapcols[nombre]->addDato(dato); }

		void get(int i)
		{
			for (auto col : tabla->mapcols)
				cout << setw(15) << col.second->getDato(i);
			cout << endl;
		}

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

	string getColName(int i) {
		int aux = 0;
		for (auto e: mapcols)
		{
			if (aux == i)
				return e.first;
			aux++;
		}
	}
	CCols* getCol(string name_col) { return mapcols[name_col]; }
	CFila* getFila(int nfila) { return maprows[nfila]; }

	
	//Función mostrar tabla en consola
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

	//Lee un archivo CSV pero con ciertas condiciones
	void readAnArch(string auxs) {
		std::ifstream	file(auxs);
		CSVRow			row;

		int aux = 0; vector<CCols*> aux_cols;
		while (file >> row)
		{
			if (aux == 0)
			{
				for (int i = 0; i < row.size(); i++)
				{
					CCols* col = new CCols(row[i]);
					aux_cols.push_back(col);		
				} aux++;
			}
			else if (aux == 1)
			{
				for (int i = 0; i < row.size(); i++)
				{
					aux_cols[i]->setName(row[i]);
					this->addCol(aux_cols[i]);
				} aux++;
			}
			else
			{
				CFila* aux_fila = this->addFila();
				int num_col = 0;
				for (auto e : mapcols) {
					aux_fila->add(e.second->getName(), row[num_col]);
					num_col++;
				}
			}
		}
	}
	//Guardar archivos con formato CSV (separado por comas ';')
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

	//Filtrado
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
	//Indexado
	void indexar(string nombre_cols)
	{
		CArbol*nuevo = new CArbol();
		arboles[nombre_cols] = nuevo;

		vector<string>aux = mapcols[nombre_cols]->getAllData();

		for (int i = 0; i < f; i++)
			nuevo->add(aux[i], i);
		cout << "La columna indexada es: " << nombre_cols << endl;

	}
	//Búsqueda
	void buscar(string nombre_col, string dato)
	{
		int existe = arboles.count(nombre_col);
		cout << "Los resultados de la búsqueda:\t";
		if (existe == 1)
		{
			cout << "(en un BST AVL)\n";
			vector<int>pos = arboles[nombre_col]->find(dato);

			for (int i = 0; i < pos.size(); i++)
				maprows[pos[i]]->get(pos[i]);
		}
		else
		{
			cout << "(secuencial)\n";
			for (int i = 0; i < f; i++)
			{
				if (mapcols[nombre_col]->findDato(i, dato))
					maprows[i]->get(i);
			}
		}
	}


	void borrar_arboles() {
		for (auto e: arboles)
			e.second->clear();
		arboles.clear();
	}
	void inorder(string nombre_col) { arboles[nombre_col]->inOrder(); }
};