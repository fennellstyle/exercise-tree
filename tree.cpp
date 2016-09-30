//
// Created by sean on 9/29/16.
//

#include <iostream>
#include <memory>
#include "tree.h"
#include <sstream>

namespace tree {
    Node::Node() : data(0), left(nullptr), right(nullptr) {}

    Node::Node(data_t m_data) : data(m_data), left(nullptr), right(nullptr) {}

    void Node::print() const {
        std::cout << display() << "\n";
    }

    std::string Node::display() const {
        std::stringstream ss;
        ss << "Node(" << data << ")";
        return ss.str();
    }

    void BinaryTree::print() const {
        if (m_root == nullptr)
        {
            std::cout << "BinaryTree has no root." << std::endl;
            return;
        }

        std::cout << "root: ";
        print(m_root);
    }

// todo: use node->display()
// todo: get this working to show tree nested
    void BinaryTree::print(const node_ref_t &node) const {
        if (node == nullptr) {
            return;
        }

        node->print();
        print(node->left);
        print(node->right);
    }

    void BinaryTree::insert(data_t value) {
        insert(m_root, value);
    }

    void BinaryTree::insert(node_ref_t &root, data_t value) {
        if (root == nullptr) {
            root = std::make_shared<Node>(Node(value));
            return;
        }

        if (value < root->data) {
            insert(root->left, value);
        } else {
            insert(root->right, value);
        }
    }

    // todo: get this working to show tree nested
    std::ostream &operator<<(std::ostream &os, const BinaryTree &tree1) {
        if (tree1.m_root == nullptr) {
            return os << "BinaryTree(empty)";
        }

        os << "BinaryTree(" << tree1.m_root->data << ")\n";
        if (tree1.m_root->left != nullptr)
            os <<  tree1.m_root->left->data;

        if (tree1.m_root->right != nullptr)
            os << "\t" << tree1.m_root->right->data;

        return os;
    }

    const node_ref_t &BinaryTree::getRoot() const {
        return m_root;
    }
}
