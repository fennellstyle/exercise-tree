//
// Created by sean on 9/29/16.
//

#include <iostream>
#include "tree.h"

tree::Node::Node() : data(0), left(nullptr), right(nullptr){}

tree::Node::Node(tree::data_t m_data) : data(m_data), left(nullptr), right(nullptr) {}

void tree::Node::print() {
    std::cout << data << "\n";
}

void tree::Tree::print() {
    if (m_root == nullptr) {
        std::cout << "Tree has no root." << std::endl;
        return;
    }

    std::cout << "root: ";
    m_root->print();
    if (m_root->left != nullptr) {
        std::cout << "left: ";
        m_root->left->print();
    }

    if (m_root->right != nullptr) {
        std::cout << "right: ";
        m_root->right->print();
    }
}

void tree::Tree::insert(tree::data_t value) {
    m_root = tree::node_ref_t(new tree::Node(value));
}

