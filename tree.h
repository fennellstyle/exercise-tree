//
// Created by sean on 9/29/16.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <memory>

namespace tree {
    class Node;
    using data_t = int;
    using node_ref_t = std::shared_ptr<Node>;
    node_ref_t makeNode(data_t);

    struct Node {
        Node();
        Node(data_t);

        data_t data;
        node_ref_t left;
        node_ref_t right;
    };

    class BinaryTree {
    public:
        const node_ref_t &getRoot() const;
        void insert(data_t);

    private:
        void insert(node_ref_t &, data_t);
        node_ref_t m_root;
    };

}

#endif //TREE_TREE_H
