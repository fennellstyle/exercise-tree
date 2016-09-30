//
// Created by sean on 9/29/16.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <memory>
#include <ostream>

namespace tree {
    class Node;
    using data_t = int;
    using node_ref_t = std::shared_ptr<Node>;

    struct Node {
        Node();
        Node(data_t);
        void print() const;
        std::string display() const;


        data_t data;
        node_ref_t left;
        node_ref_t right;
    };

    class BinaryTree {
    public:
        void insert(data_t);
        void print() const;
        void print(const node_ref_t &node) const;
        const node_ref_t &getRoot() const;

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree &tree1);

    private:
        node_ref_t m_root;
        void insert(node_ref_t &, data_t);
    };

}

#endif //TREE_TREE_H
