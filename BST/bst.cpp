//Binary Search Tree, implementation
//Week 12
//Fall 2014

#include <cassert>
using namespace std;
#include "bst.h"

BST::BST () {
    root = NULL;
}


void BST::insertItem(TreeNode*& t,  string x) {
    if (t==NULL) {
        t = new TreeNode;
        t->data = x;
        t->left = NULL;
        t->right = NULL;
    }
    else if (x < t->data)
        insertItem (t->left, x);
    
    else if (x > t->data)
        insertItem (t->right, x);
    
    //else x == data(t), do nothing, no duplicates
}

bool BST::findItem(TreeNode* t, string x) {
    if (t==NULL)
        return false;
    
    if (x < t->data)
        return findItem(t->left, x);
    
    if (x > t->data)
        return findItem(t->right, x);
    
    return true;
    
}

//This is the Weiss strategy
void BST::removeItem(TreeNode*& t, string x) {
    if (t==NULL)
        return;
    
    if (x < t->data)
        return removeItem(t->left, x);
    
    if (x > t->data)
        return removeItem(t->right, x);
    
    // t->data == x
    TreeNode *temp = t;
    if (!t->left) {
        t = t->right;
        delete(temp);
    }
    
    else if (!t->right) {
        t = t->left;
        delete (temp);
    }
    
    else { // 2 children
        TreeNode *p = t->right; //not null
        while (p->left)
            p = p->left;
        t->data = p->data;  //copy the value
        removeMin(t->right);
    }
}

void BST::removeMin(TreeNode *& t) {
    if (t->left)
        removeMin(t->left);
    else {
        TreeNode *temp = t;
        t = t->right;
        delete (temp);
    }
}

//This is the Gaddis strategy
//void BST::removeItem(TreeNode*& t, string x) {
//    if (t==NULL)
//        return;
//    
//    if (x < t->data)
//        return removeItem(t->left, x);
//    
//    if (x > t->data)
//        return removeItem(t->right, x);
//    
//    // t->data == x
//    TreeNode *temp = t;
//    
//    if (!t->right) {
//        t = t->left;
//        delete (temp);
//    }
//    
//    else { // right child is not null
//        TreeNode *p = t->right; //not null
//        while (p->left)
//            p = p->left;
//        p->left = t->left;
//        t = t->right;
//        delete (temp);
//    }
//}



