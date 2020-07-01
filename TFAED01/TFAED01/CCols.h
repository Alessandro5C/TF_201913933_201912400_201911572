#pragma once
#include <iostream>
#include <vector>
//#include <utility>
#include <string>

using namespace std;
//template <class T>
class CCols
{
private:
	string name;
	string type;
	vector<string> data;
public:
	CCols(string name, string type)
		: name(name), type(type) {}
	~CCols() {}

	string getName() { return name; }
	string getType() { return type; }
	string getDato(int nfila) { return data.at(nfila); }
	vector<string> getAllData() { return data; }

	void addDato(string dato) { data.push_back(dato); }
	void setDato(int nfila, string dato) { data[nfila] = dato; }

};
