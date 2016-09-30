#include <iostream>
#include "tree.h"

using namespace std;
using namespace tree;
int main() {
    BinaryTree myTree;
    myTree.print();
    myTree.insert(17);
    myTree.print();
    cout << myTree.getRoot()->display() << endl;

    myTree.insert(1);
    myTree.print();

    myTree.insert(12);
    myTree.print();

    myTree.insert(5);
    myTree.print();

    myTree.insert(25);
    myTree.print();
    return 0;
}


