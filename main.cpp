#include <iostream>
#include "tree.h"
#include "tree_algorithm.h"
#include "binary_tree_pretty_print.h"

using namespace std;
using namespace tree;
using namespace algorithm;

int main() {
    BinaryTree<double> myTree;
    printPretty(myTree.getRoot(), 1, 0, cout);
    insert(myTree, 17.1);
    printPretty(myTree.getRoot(), 1, 0, cout);

    insert(myTree, 1.2);
    printPretty(myTree.getRoot(), 1, 0, cout);

    insert(myTree, 12.3);
    printPretty(myTree.getRoot(), 1, 0, cout);

    insert(myTree, 5.4);
    printPretty(myTree.getRoot(), 1, 0, cout);

    insert(myTree, 25.5);
    printPretty(myTree.getRoot(), 1, 0, cout);
    return 0;
}


