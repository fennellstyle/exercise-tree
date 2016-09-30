//#include <iostream>
#include "tree.h"

using namespace std;
using namespace tree;
int main() {
    Tree myTree;
    myTree.print();
    myTree.insert(0);
    myTree.print();
    myTree.insert(1);
    myTree.print();
    return 0;
}