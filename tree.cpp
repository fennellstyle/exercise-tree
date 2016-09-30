//
// Created by sean on 9/29/16.
//

#include <iostream>
#include <memory>
#include "tree.h"
#include <sstream>

tree::Node::Node() : data(0), left(nullptr), right(nullptr) {}

tree::Node::Node(tree::data_t m_data) : data(m_data), left(nullptr), right(nullptr) {}

void tree::Node::print() const {
    std::cout << display() << "\n";
}

std::string tree::Node::display() const {
    std::stringstream ss;
    ss << "Node(" << data << ")";
    return ss.str();
}

void tree::Tree::print() const {
    if (m_root == nullptr)
    {
        std::cout << "Tree has no root." << std::endl;
        return;
    }

    std::cout << "root: ";
    print(m_root);
}

// todo: use node->display()
// todo: get this working to show tree nested
void tree::Tree::print(const node_ref_t &node) const {
    if (node == nullptr) {
        return;
    }

    node->print();
    print(node->left);
    print(node->right);
}

void tree::Tree::insert(tree::data_t value) {
    insert(m_root, value);
}

void tree::Tree::insert(tree::node_ref_t &root, tree::data_t value) {
    if (root == nullptr) {
        root = std::make_shared<tree::Node>(tree::Node(value));
        return;
    }

    if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

namespace tree {
// todo: get this working to show tree nested
std::ostream &operator<<(std::ostream &os, const tree::Tree &tree1) {
    if (tree1.m_root == nullptr) {
        return os << "Tree(empty)";
    }

    os << "Tree(" << tree1.m_root->data << ")\n";
    if (tree1.m_root->left != nullptr)
        os <<  tree1.m_root->left->data;

    if (tree1.m_root->right != nullptr)
        os << "\t" << tree1.m_root->right->data;

    return os;
}

    const node_ref_t &Tree::getRoot() const {
        return m_root;
    }
}
