//
// Created by sean on 9/30/16.
//

#include "tree.h"

#ifndef TREE_TREE_ALGORITHM_H
#define TREE_TREE_ALGORITHM_H

namespace algorithm {

    template <typename V>
    std::shared_ptr<tree::Node<V>> makeNode(V value) {
        return std::make_shared<tree::Node<V>>(value);
    }

    template <typename T, typename V>
    void _insert(T &root, V value) {
        if (!root) {
            root = makeNode(value);
            return;
        }

        if (value < root->data) {
            _insert(root->left, value);
        } else {
            _insert(root->right, value);
        }
    }

    template <class T, typename V>
    void insert(T &tree, V value) {
        _insert(tree.getRoot(), value);
    }

}

#endif //TREE_TREE_ALGORITHM_H
