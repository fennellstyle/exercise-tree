//
// Created by sean on 9/29/16.
//

#include <memory>
#include "tree.h"

namespace tree {

    template <class T>
    Node<T>::Node() : data{}, left{nullptr}, right{nullptr} {}

    template <class T>
    Node<T>::Node(T data) : data{data}, left{nullptr}, right{nullptr} {}

    template <class T>
    const typename BinaryTree<T>::node_ref_t &BinaryTree<T>::getRoot() const {
        return this->template m_root;
    }

    template <class T>
    typename BinaryTree<T>::node_ref_t &BinaryTree<T>::getRoot() {
        return this->template m_root;
    }

    template class Node<int>;
    template class Node<float>;
    template class Node<double>;

    template class BinaryTree<int>;
    template class BinaryTree<float>;
    template class BinaryTree<double>;
}
