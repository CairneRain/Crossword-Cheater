//implementation of red-black tree

#include"RBTree.h"
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const bool RED = true;
const bool BLACK = false;

//The constructor of node of the tree
Node::Node(string key, int val,bool color){
	this->key = key;
	this->val = val;
	this->color = color;
}


//public functions
int RBTree::get(string key) {
	return get(this->root, key);
}

int RBTree::get(Node* x, string key) {
	//if the x is not a null node
	while (x != NULL) {
		string xkey = x->key;
		
		//if the current key is bigger than search key, go left
		if (xkey > key) x = x->left;
		
		//if the current key is smaller than search key, go right
		else if (xkey < key) x = x->right;

		//if equals, return its value
		else return x->val;
	}
	return NULL;
}

bool RBTree::contains(string key) {
	return get(key) != NULL;
}

//put a new node into the tree
void RBTree::put(string key, int val) {
	this->root = insert(this->root, key, val);
	root->color = BLACK;
}

int RBTree::size() {
	return this->n;
}

bool RBTree::isEmpty() {
	return this->n == 0;
}

int RBTree::height() {
	return height(this->root);
}

int RBTree::height(Node* x) {
	if (x == NULL)return -1;
	return 1 + std::max(height(x->left), height(x->right));
}

string RBTree::min() {
	return min(this->root);
}

string RBTree::min(Node* x) {
	string key = "";
	
	//find the most left node
	while (x != NULL) {
		key = x->key;
		x = x->left;
	}
	return key;
}

string RBTree::max() {
	return max(this->root);
}

string RBTree::max(Node* x) {
	string key = "";

	//find the most right node
	while (x != NULL) {
		key = x->key;
		x = x->right;
	}
	return key;
}

//get all keys in alphabetical order
void RBTree::keys(vector<Words>&vec) {

	keys(root, vec);

	//sort by frequency and descending order
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

}
void RBTree::keys(Node* x, vector<Words> &vec) {
	if (x == NULL) return;
	keys(x->left, vec);
	Words word;
	word.word = x->key;
	word.frequence = x->val;
	vec.push_back(word);
	keys(x->right, vec);
}

//private functions
Node* RBTree::insert(Node*& h, string key, int val) {

	//if it is the first node inserting to the tree
	if (h == NULL) {
		this->n++;
		return new Node(key, val, RED);
	}

	//if the key of inserting node is smaller than current key, go left
	if (key < h->key) h->left = insert(h->left, key, val);

	//if the key of inserting node is bigger than current key, go right
	else if (key > h->key) h->right = insert(h->right, key, val);

	//if equals, add the value together
	else h->val += val;

	//this is a left-leaning RBTree, key red is always on the left
	if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
	//if there are two successive red nodes
	if (isRed(h->left) && isRed(h->left->left))h = rotateRight(h);
	if (isRed(h->left) && isRed(h->right)) flipColors(h);

	return h;
}

bool RBTree::isRed(Node* x) {
	if (x == NULL) return false;
	return x->color == RED;
}

Node* RBTree::rotateRight(Node* &h) {
	Node* x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	return x;
}

Node* RBTree::rotateLeft(Node* &h) {
	Node* x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED;
	return x;
}

void RBTree::flipColors(Node* h) {
	h->color = RED;
	h->left->color = BLACK;
	h->right->color = BLACK;
}