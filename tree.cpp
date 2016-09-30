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

    void Node::setLeft(data_t value) {
        left = makeNode(value);
    }

    void Node::setRight(data_t value) {
        right = makeNode(value);
    }

    const node_ref_t &BinaryTree::getRoot() const {
        return m_root;
    }

    node_ref_t BinaryTree::findInsertionPoint(node_ref_t parent, data_t value) {
        auto insertionPoint = value < parent->data
                              ? parent->left
                              : parent->right;
        return insertionPoint
            ? findInsertionPoint(insertionPoint, value)
            : parent;
    }

    void BinaryTree::insert(data_t value) {
        if (!m_root) {
            setRoot(value);
            return;
        }

        auto insertIterator = m_root;
        decltype(m_root) parent = nullptr;

        while(insertIterator) {
            parent = insertIterator;
            insertIterator = value < insertIterator->data
                             ? insertIterator->left
                             : insertIterator->right;
        }

        if (value < parent->data)
            parent->setLeft(value);
        if (value > parent->data)
            parent->setRight(value);
    }

    void BinaryTree::insert(node_ref_t &root, data_t value) {
        // tempNode is the node to insert
        auto current = node_ref_t(nullptr);
        auto parent = node_ref_t(nullptr);

        // if root is null set the root and exit
        if (!root) {
            root = makeNode(value);
            return;
        } else {
            // set our current node to the root
            current = root;
        }

        // iterate over all the nodes until insertion point is found
        while(true) {
            // track the current node as the parent
            parent = current;

            // if our value is less than the parent insert to the left
            if (value < parent->data) {
                // left insertion point is the left of the current node
                current = current->left;
                if(current->left and value > current->left->data)
                insert(parent->left, value);
                return;
            } else {  // insertion point is to the right
                // right insertion point is the right of the current node
                current = current->right;
                insert(parent->right, value);
                return;
            }
        }
    }

    void BinaryTree::setRoot(data_t value) {
        m_root = makeNode(value);

    }

}
