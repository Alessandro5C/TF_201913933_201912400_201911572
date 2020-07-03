#pragma once
#include "CTabla.h"

///Para filtraciones
function<bool(string, string, string)> fx_primero;

function<bool(string, string, string)>filtro_igual = [](string dato, string cmp, string type)
{
	if (type == "int") { return stoi(dato) == stoi(cmp); }
	else if (type == "double") { return stof(dato) == stof(cmp); }
	else { return dato == cmp; }
};

function<bool(string, string, string)>filtro_menor = [](string dato, string cmp, string type)
{
	if (type == "int") { return stoi(dato) < stoi(cmp); }
	else if (type == "double") { return stof(dato) < stof(cmp); }
	else { return dato < cmp; }
};

function<bool(string, string, string)>filtro_mayor = [](string dato, string cmp, string type) {
	if (type == "int") { return stoi(dato) > stoi(cmp); }
	else if (type == "double") { return stof(dato) > stof(cmp); }
	else { return dato > cmp; }
};

function<bool(string, string, string)>filtro_contenido = [](string dato, string cmp, string type)
{
	size_t found = dato.find(cmp);
	return found != string::npos;

};

function<bool(string, string, string)>filtro_nocontenido = [](string dato, string cmp, string type)
{
	size_t found = dato.find(cmp);
	return found == string::npos;
};

function<bool(string, string, string)>filtro_inicia = [](string dato, string cmp, string type)
{
	size_t found = dato.find(cmp);
	return found == 0;
};

function<bool(string, string, string)>filtro_finaliza = [](string dato, string cmp, string type)
{
	int found = dato.find(cmp);
	return found == dato.size() - cmp.size();
};

///Para ordenamientos
//para int's
void maxheapify(vector<int>& arr, int n, int i, CTabla* taux)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		//
		taux->getFila(i)->cambiar(largest);
		//
		maxheapify(arr, n, largest, taux);
	}
}
void maxheapSort(vector<int>& arr, int n, CTabla* taux)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		maxheapify(arr, n, i, taux);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		//
		taux->getFila(0)->cambiar(i);
		//
		maxheapify(arr, i, 0, taux);
	}
}

void minheapify(vector<int>& arr, int n, int i, CTabla* taux)
{
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] < arr[smallest])
		smallest = l;
	if (r < n && arr[r] < arr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		//
		taux->getFila(i)->cambiar(smallest);
		//
		minheapify(arr, n, smallest, taux);
	}
}
void minheapSort(vector<int>& arr, int n, CTabla* taux)
{
	pair<int, string> auxp;
	for (int i = n / 2 - 1; i >= 0; i--)
		minheapify(arr, n, i, taux);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		//
		taux->getFila(0)->cambiar(i);
		//
		minheapify(arr, i, 0, taux);
	}
}
//para double's
void maxheapify(vector<double>& arr, int n, int i, CTabla* taux)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		//
		taux->getFila(i)->cambiar(largest);
		//
		maxheapify(arr, n, largest, taux);
	}
}
void maxheapSort(vector<double>& arr, int n, CTabla* taux)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		maxheapify(arr, n, i, taux);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		//
		taux->getFila(0)->cambiar(i);
		//
		maxheapify(arr, i, 0, taux);
	}
}

void minheapify(vector<double>& arr, int n, int i, CTabla* taux)
{
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] < arr[smallest])
		smallest = l;
	if (r < n && arr[r] < arr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		//
		taux->getFila(i)->cambiar(smallest);
		//
		minheapify(arr, n, smallest, taux);
	}
}
void minheapSort(vector<double>& arr, int n, CTabla* taux)
{
	pair<int, string> auxp;
	for (int i = n / 2 - 1; i >= 0; i--)
		minheapify(arr, n, i, taux);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		//
		taux->getFila(0)->cambiar(i);
		//
		minheapify(arr, i, 0, taux);
	}
}

//para string's
void maxheapify(vector<string>& arr, int n, int i, CTabla* taux)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		//
		taux->getFila(i)->cambiar(largest);
		//
		maxheapify(arr, n, largest, taux);
	}
}
void maxheapSort(vector<string>& arr, int n, CTabla* taux)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		maxheapify(arr, n, i, taux);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		//
		taux->getFila(0)->cambiar(i);
		//
		maxheapify(arr, i, 0, taux);
	}
}

void minheapify(vector<string>& arr, int n, int i, CTabla* taux)
{
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] < arr[smallest])
		smallest = l;
	if (r < n && arr[r] < arr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		//
		taux->getFila(i)->cambiar(smallest);
		//
		minheapify(arr, n, smallest, taux);
	}
}
void minheapSort(vector<string>& arr, int n, CTabla* taux)
{
	pair<int, string> auxp;
	for (int i = n / 2 - 1; i >= 0; i--)
		minheapify(arr, n, i, taux);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		//
		taux->getFila(0)->cambiar(i);
		//
		minheapify(arr, i, 0, taux);
	}
}
