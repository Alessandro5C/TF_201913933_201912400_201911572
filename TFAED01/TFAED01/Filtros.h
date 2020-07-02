#include "HeapSort.h"
//function<bool(string, string)>filtro_mayor = [](string dato, string cmp) { return dato > cmp; };
//function<bool(string, string)>filtro_menor = [](string dato, string cmp) { return dato < cmp; };
//function<bool(string, string)>filtro_inicia = [](string dato, string cmp)
//{
//	size_t found = dato.find(cmp);
//	return found == 0;
//};
//function<bool(string, string)>filtro_finaliza = [](string dato, string cmp)
//{
//	size_t found = dato.find(cmp);
//	return found == dato.size() - cmp.size();
//};
//function<bool(string, string)>filtro_contenido = [](string dato, string cmp)
//{
//	size_t found = dato.find(cmp);
//	return found != string::npos;
//};
//function<bool(string, string)>filtro_nocontenido = [](string dato, string cmp)
//{
//	size_t found = dato.find(cmp);
//	return found == string::npos;
//};
//
//function<bool(string, string)>filtro_igual = [](string dato, string cmp) { return dato == cmp; };
//
//function<bool(string, string)>filtro_igual_int = [](string dato, string cmp) { return stoi(dato) == stoi(cmp); };
//function<bool(string, string)>filtro_igual_double = [](string dato, string cmp) { return stod(dato) == stod(cmp); };

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
	else { return dato > cmp; }
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
	return found == string::npos; // npos: no esta contenido
};

function<bool(string, string, string)>filtro_inicia = [](string dato, string cmp, string type)
{
	size_t found = dato.find(cmp);
	return found == 0;
};

function<bool(string, string, string)>filtro_finaliza = [](string dato, string cmp, string type)
{
	int found = dato.find(cmp); // dato = "Pedro" (5) cmp="dro"(3) = 2 // lo cambie a int
	return found == dato.size() - cmp.size();
};
