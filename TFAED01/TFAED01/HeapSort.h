#pragma once
#include "CTabla.h"

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
		taux->getFila(0)->cambiar(i, largest);
		//taux->swapFilas(i, largest);
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
		taux->getFila(0)->cambiar(0, i);
		//taux->swapFilas(0, i);
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
		taux->getFila(0)->cambiar(i, smallest);
		//taux->swapFilas(i, largest);
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
		taux->getFila(0)->cambiar(0, i);
		//taux->swapFilas(i, largest);
		//
		minheapify(arr, i, 0, taux);
	}
}

/*
void maxheapify(vector<double>& arr, int n, int i, CTabla* grup)
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
		pair<int, string> auxp;
		for (int idxg = 0; idxg < grup->getidxl_tipo().size(); idxg++)
		{
			auxp.first = grup->getidxl_tipo()[idxg].first;
			auxp.second = grup->getidxl_tipo()[idxg].second;
			if (auxp.second == "int")
				swap(grup->getGroupInt()[auxp.first].getarreglo()[i],
					grup->getGroupInt()[auxp.first].getarreglo()[largest]);
			else if (auxp.second == "double")
				swap(grup->getGroupDouble()[auxp.first].getarreglo()[i],
					grup->getGroupDouble()[auxp.first].getarreglo()[largest]);
			else if (auxp.second == "char")
				swap(grup->getGroupChar()[auxp.first].getarreglo()[i],
					grup->getGroupChar()[auxp.first].getarreglo()[largest]);
		}
		maxheapify(arr, n, largest, grup);
	}
}
void maxheapSort(vector<double>& arr, int n, CTabla* grup)
{
	pair<int, string> auxp;
	for (int i = n / 2 - 1; i >= 0; i--)
		maxheapify(arr, n, i, grup);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		for (int idxg = 0; idxg < grup->getidxl_tipo().size(); idxg++)
		{
			auxp.first = grup->getidxl_tipo()[idxg].first;
			auxp.second = grup->getidxl_tipo()[idxg].second;
			if (auxp.second == "int")
				swap(grup->getGroupInt()[auxp.first].getarreglo()[0],
					grup->getGroupInt()[auxp.first].getarreglo()[i]);
			else if (auxp.second == "double")
				swap(grup->getGroupDouble()[auxp.first].getarreglo()[0],
					grup->getGroupDouble()[auxp.first].getarreglo()[i]);
			else if (auxp.second == "char")
				swap(grup->getGroupChar()[auxp.first].getarreglo()[0],
					grup->getGroupChar()[auxp.first].getarreglo()[i]);
		}
		maxheapify(arr, i, 0, grup);
	}
}

void maxheapify(vector<char>& arr, int n, int i, CTabla* grup)
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
		pair<int, string> auxp;
		for (int idxg = 0; idxg < grup->getidxl_tipo().size(); idxg++)
		{
			auxp.first = grup->getidxl_tipo()[idxg].first;
			auxp.second = grup->getidxl_tipo()[idxg].second;
			if (auxp.second == "int")
				swap(grup->getGroupInt()[auxp.first].getarreglo()[i],
					grup->getGroupInt()[auxp.first].getarreglo()[largest]);
			else if (auxp.second == "double")
				swap(grup->getGroupDouble()[auxp.first].getarreglo()[i],
					grup->getGroupDouble()[auxp.first].getarreglo()[largest]);
			else if (auxp.second == "char")
				swap(grup->getGroupChar()[auxp.first].getarreglo()[i],
					grup->getGroupChar()[auxp.first].getarreglo()[largest]);
		}
		maxheapify(arr, n, largest, grup);
	}
}
void maxheapSort(vector<char>& arr, int n, CTabla* grup)
{
	pair<int, string> auxp;
	for (int i = n / 2 - 1; i >= 0; i--)
		maxheapify(arr, n, i, grup);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		for (int idxg = 0; idxg < grup->getidxl_tipo().size(); idxg++)
		{
			auxp.first = grup->getidxl_tipo()[idxg].first;
			auxp.second = grup->getidxl_tipo()[idxg].second;
			if (auxp.second == "int")
				swap(grup->getGroupInt()[auxp.first].getarreglo()[0],
					grup->getGroupInt()[auxp.first].getarreglo()[i]);
			else if (auxp.second == "double")
				swap(grup->getGroupDouble()[auxp.first].getarreglo()[0],
					grup->getGroupDouble()[auxp.first].getarreglo()[i]);
			else if (auxp.second == "char")
				swap(grup->getGroupChar()[auxp.first].getarreglo()[0],
					grup->getGroupChar()[auxp.first].getarreglo()[i]);
		}
		maxheapify(arr, i, 0, grup);
	}
}



void minheapify(vector<double>& arr, int n, int i, CTabla* grup)
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
		pair<int, string> auxp;
		for (int idxg = 0; idxg < grup->getidxl_tipo().size(); idxg++)
		{
			auxp.first = grup->getidxl_tipo()[idxg].first;
			auxp.second = grup->getidxl_tipo()[idxg].second;
			if (auxp.second == "int")
				swap(grup->getGroupInt()[auxp.first].getarreglo()[i],
					grup->getGroupInt()[auxp.first].getarreglo()[smallest]);
			else if (auxp.second == "double")
				swap(grup->getGroupDouble()[auxp.first].getarreglo()[i],
					grup->getGroupDouble()[auxp.first].getarreglo()[smallest]);
			else if (auxp.second == "char")
				swap(grup->getGroupChar()[auxp.first].getarreglo()[i],
					grup->getGroupChar()[auxp.first].getarreglo()[smallest]);
		}
		minheapify(arr, n, smallest, grup);
	}
}
void minheapSort(vector<double>& arr, int n, CTabla* grup)
{
	pair<int, string> auxp;
	for (int i = n / 2 - 1; i >= 0; i--)
		minheapify(arr, n, i, grup);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		for (int idxg = 0; idxg < grup->getidxl_tipo().size(); idxg++)
		{
			auxp.first = grup->getidxl_tipo()[idxg].first;
			auxp.second = grup->getidxl_tipo()[idxg].second;
			if (auxp.second == "int")
				swap(grup->getGroupInt()[auxp.first].getarreglo()[0],
					grup->getGroupInt()[auxp.first].getarreglo()[i]);
			else if (auxp.second == "double")
				swap(grup->getGroupDouble()[auxp.first].getarreglo()[0],
					grup->getGroupDouble()[auxp.first].getarreglo()[i]);
			else if (auxp.second == "char")
				swap(grup->getGroupChar()[auxp.first].getarreglo()[0],
					grup->getGroupChar()[auxp.first].getarreglo()[i]);
		}
		minheapify(arr, i, 0, grup);
	}
}

void minheapify(vector<char>& arr, int n, int i, CTabla* grup)
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
		pair<int, string> auxp;
		for (int idxg = 0; idxg < grup->getidxl_tipo().size(); idxg++)
		{
			auxp.first = grup->getidxl_tipo()[idxg].first;
			auxp.second = grup->getidxl_tipo()[idxg].second;
			if (auxp.second == "int")
				swap(grup->getGroupInt()[auxp.first].getarreglo()[i],
					grup->getGroupInt()[auxp.first].getarreglo()[smallest]);
			else if (auxp.second == "double")
				swap(grup->getGroupDouble()[auxp.first].getarreglo()[i],
					grup->getGroupDouble()[auxp.first].getarreglo()[smallest]);
			else if (auxp.second == "char")
				swap(grup->getGroupChar()[auxp.first].getarreglo()[i],
					grup->getGroupChar()[auxp.first].getarreglo()[smallest]);
		}
		minheapify(arr, n, smallest, grup);
	}
}
void minheapSort(vector<char>& arr, int n, CTabla* grup)
{
	pair<int, string> auxp;
	for (int i = n / 2 - 1; i >= 0; i--)
		minheapify(arr, n, i, grup);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		for (int idxg = 0; idxg < grup->getidxl_tipo().size(); idxg++)
		{
			auxp.first = grup->getidxl_tipo()[idxg].first;
			auxp.second = grup->getidxl_tipo()[idxg].second;
			if (auxp.second == "int")
				swap(grup->getGroupInt()[auxp.first].getarreglo()[0],
					grup->getGroupInt()[auxp.first].getarreglo()[i]);
			else if (auxp.second == "double")
				swap(grup->getGroupDouble()[auxp.first].getarreglo()[0],
					grup->getGroupDouble()[auxp.first].getarreglo()[i]);
			else if (auxp.second == "char")
				swap(grup->getGroupChar()[auxp.first].getarreglo()[0],
					grup->getGroupChar()[auxp.first].getarreglo()[i]);
		}
		minheapify(arr, i, 0, grup);
	}
}
*/