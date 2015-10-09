//Binary Search Tree, driver
//Week 12
//Fall 2014

#include <iostream>
using namespace std;

#include "BST.h"


int main() {
    BST t1;
    
    t1.insertItem("Apple");
    t1.insertItem("Pineapple");
    t1.insertItem("Watermelon");
    t1.insertItem("Banana");
    t1.insertItem("Lemon");
    t1.insertItem("Lime");

    if (t1.findItem("Banana"))
        cout << "Found Banana" << endl;
    else
        cout << "did NOT find Banana" << endl;

    if (t1.findItem("Papaya"))
        cout << "Found Papaya" << endl;
    else
        cout << "did NOT find Papaya" << endl;

    t1.removeItem("Banana");
    if (t1.findItem("Banana"))
        cout << "Found Banana" << endl;
    else
        cout << "did NOT find Banana" << endl;
    
    t1.inOrderTraversal();
}