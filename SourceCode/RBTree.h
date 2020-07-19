//implementation of red-black tree

#include<cstdlib>
#include<sstream>
#include<iostream>
#include"PartB.h"

using namespace std;

//structure of the tree node
class Node {
private:
	
public:
	Node(string, int, bool);
	string key;
	int val;
	Node* left=NULL;
	Node* right=NULL;
	bool color;
};

//red-black tree
class RBTree {

public:
	int get(string key);
	int get(Node* x, string key);
	bool contains(string key);
	void put(string key, int val);
	int size();
	bool isEmpty();
	int height();
	int height(Node* x);
	string min();
	string min(Node* x);
	string max();
	string max(Node* x);
	void keys(vector<Words>& vec);
	void keys(Node* x, vector<Words>& vec);
	RBTree() { this->root = NULL; this->n = 0; };

private:
	Node* root;
	int n;
	Node* insert(Node* &h, string key, int val);
	bool isRed(Node* x);
	Node* rotateRight(Node* &h);
	Node* rotateLeft(Node* &h);
	void flipColors(Node* h);
};
