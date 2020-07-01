#pragma once
#include "CCols.h"
#include <functional>
#include <iomanip>
#include <fstream>
#include <map>
class CTabla
{
protected:
	map<string, CCols*> mapcols;

public:
	class  CFila
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
		if (arch.is_open() == NULL)
		{
			//MessageBox::Show(L"Ha ocurrido un error, intente nuevamente.", "",
			//	MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
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
	void filtrar(string colu, string cmp, function<bool(string, string)>&lam)
	{
		for (int i = 0; i < f; i++)
		{
			if (lam(mapcols[colu]->getDato(i), cmp))
				maprows[i]->get(i);
		}
	}
};