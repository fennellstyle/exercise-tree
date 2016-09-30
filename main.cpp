#include <iostream>
#include "tree.h"
#include "binary_tree_pretty_print.h"

using namespace std;
using namespace tree;

int main() {
    BinaryTree myTree;
    printPretty(myTree.getRoot(), 1, 0, cout);
    myTree.insert(17);
    printPretty(myTree.getRoot(), 1, 0, cout);

    myTree.insert(1);
    printPretty(myTree.getRoot(), 1, 0, cout);

    myTree.insert(12);
    printPretty(myTree.getRoot(), 1, 0, cout);

    myTree.insert(5);
    printPretty(myTree.getRoot(), 1, 0, cout);

    myTree.insert(25);
    printPretty(myTree.getRoot(), 1, 0, cout);
    return 0;
}


