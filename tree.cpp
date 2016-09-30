//
// Created by sean on 9/29/16.
//

#include <memory>
#include "tree.h"

namespace tree {
    template <class T>
    typename Node<T>::node_ref_t makeNode(T value) {
        return std::make_shared<Node<T>>(Node<T>(value));
    }

    template <class T>
    Node<T>::Node() : data{}, left{nullptr}, right{nullptr} {}

    template <class T>
    Node<T>::Node(T data) : data{data}, left{nullptr}, right{nullptr} {}

    template <class T>
    const typename BinaryTree<T>::node_ref_t &BinaryTree<T>::getRoot() const {
        return this->template m_root;
    }

    template <class T>
    void BinaryTree<T>::insert(T value) {
        insert(m_root, value);
    }

    template <class T>
    void BinaryTree<T>::insert(BinaryTree<T>::node_ref_t &root, T value) {
        if (!root) {
            root = makeNode<T>(value);
            return;
        }

        if (value < root->data) {
            insert(root->left, value);
        } else {
            insert(root->right, value);
        }
    }

    template class BinaryTree<int>;
    template class BinaryTree<float>;
    template class BinaryTree<double>;
}
