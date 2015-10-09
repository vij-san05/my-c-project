//Binary Search Tree, specification
//Week 12
//Fall 2014

#include <iostream>
#include <cassert>

using namespace std;

class BST {

private:
	struct TreeNode {
		string data;
		TreeNode *left;
		TreeNode *right;
	};

	TreeNode * root;

	//Private functions that are called from the public functions
	bool findItem(TreeNode*, string);
	void insertItem(TreeNode*&, string);
	void removeItem(TreeNode*&, string);
	void removeMin(TreeNode *& t);
	void inOrderTraversal(TreeNode *p) {
		if (p) {
			inOrderTraversal(p->left);
			cout << p->data << " ";
			inOrderTraversal(p->right);
		}
	}

public:
	//Constructor
	BST();

	void insertItem(string x) {
		insertItem(root, x);
	}

	bool findItem(string x) {
		return findItem(root, x);
	}

	void removeItem(string x) {
		removeItem(root, x);
	}

	void inOrderTraversal() {
		inOrderTraversal(root);
		cout << endl;
	}
};

