//
// Created by sean on 9/29/16.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <memory>

namespace tree {
    class Node;
    using data_t = int;
    using node_ref_t = std::unique_ptr<Node>;

    struct Node {
        Node();
        Node(data_t);
        void print();

        data_t data;
        node_ref_t left;
        node_ref_t right;
    };

    class Tree {
    public:
        void insert(data_t);
        void print();
    private:
        node_ref_t m_root;
    };
}

#endif //TREE_TREE_H
