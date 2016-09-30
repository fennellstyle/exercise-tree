//
// Created by sean on 9/29/16.
//

#include <memory>
#include "tree.h"

namespace tree {
    node_ref_t makeNode(data_t value) {
        return std::make_shared<Node>(Node(value));
    }

    Node::Node() : data{0}, left{nullptr}, right{nullptr} {}

    Node::Node(data_t m_data) : data{m_data}, left{nullptr}, right{nullptr} {}

    const node_ref_t &BinaryTree::getRoot() const {
        return m_root;
    }

    void BinaryTree::insert(data_t value) {
        insert(m_root, value);
    }

    void BinaryTree::insert(node_ref_t &root, data_t value) {
        if (!root) {
            root = makeNode(value);
            return;
        }

        if (value < root->data) {
            insert(root->left, value);
        } else {
            insert(root->right, value);
        }
    }

}
