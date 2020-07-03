#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class CArbol
{
	struct Node {
		int i;
		int height;
		string elem;
		Node*right;
		Node*left;

		Node(string elem, int i)
		{
			this->elem = elem; this->i = i;
			right = nullptr; left = nullptr;
			height = 0;
		}
	};
	Node*root;
	int len;
public:
	CArbol () :root(nullptr), len(0) {}
	~CArbol () { clear(root); }
	int height () { return height(root); }
	int size () { return len; }
	void clear () { clear(root); len = 0; }
	void add (string elem, int i) { add(root, elem, i); }

	vector<int> find(string elem) {
		Node*aux = root;
		vector<int>pos;

		while (aux != nullptr) {
			int indice = find(aux, elem);
			if (indice != -1)
				pos.push_back(indice);
		}
		return pos;
	}

	void inOrder() { inOrder(root); }

private:
	void clear (Node*& node)
	{
		if (node != nullptr)
		{
			clear(node->right);
			clear(node->left);
			delete node;
			node = nullptr;
		}
	}
	int height (Node*node)
	{
		return node == nullptr ? -1 : node->height;
	}

	void balance (Node*&node)
	{
		int hl = height(node->left);
		int hr = height(node->right);

		if (hr - hl < -1)
		{
			hl = height(node->left->left);
			hr = height(node->left->right);

			if (hr>hl)
				rotateLeft(node->left);
			rotateRight(node);
		}
		else
		{
			if (hr - hl > 1)
			{
				hl = height(node->right->left);
				hr = height(node->right->right);
				if (hl > hr)
					rotateRight(node->right);
				rotateLeft(node);
			}
			else {
				updateHeight(node);
			}
		}

	}
	void add (Node*& node, string elem, int i)
	{
		if (node == nullptr)
		{
			node = new Node(elem, i);
			len++;
		}
		else
		{
			if (elem <= node->elem)
				add(node->left, elem, i);
			else
			{
				if (elem > node->elem)
					add(node->right, elem, i);
			}
			balance(node);
		}
	}
	int find (Node*& node, string elem)
	{
		if (node != nullptr)
		{
			if (elem == node->elem)
			{
				Node*aux = node;
				node = node->left;
				return aux->i;
			}
			else
			{
				if (elem <= node->elem)
				{
					node = node->left;
					return find(node, elem);
				}
				else {
					if (elem > node->elem)
					{
						node = node->right;
						return find(node, elem);
					}
				}
			}
		}
		return -1;
	}

	void rotateLeft (Node*&node)
	{
		Node*aux = node->right;
		node->right = aux->left;
		updateHeight(node);
		aux->left = node;
		updateHeight(aux);
		node = aux;
	}
	void rotateRight (Node*&node)
	{
		Node*aux = node->left;
		node->left = aux->right;
		updateHeight(node);
		aux->right = node;
		updateHeight(aux);
		node = aux;
	}

	void updateHeight (Node*node)
	{
		if (node != nullptr)
		{
			int hl = height(node->left);
			int hr = height(node->right);

			node->height = std::fmax(hl, hr) + 1;
		}
	}
	void inOrder (Node*node)
	{
		if (node != nullptr)
		{
			inOrder(node->left);
			cout << node->elem << " " << node->i << endl;
			inOrder(node->right);
		}
	}
};