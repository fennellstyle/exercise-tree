//
// Created by sean on 9/29/16.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <memory>

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


namespace tree {
    template <class T>
    struct Node {
        typedef std::shared_ptr<Node<T>> node_ref_t;

        Node();
        Node(T);

        T data;
        node_ref_t left;
        node_ref_t right;
    };

    template <class T>
    class BinaryTree {
    public:
        typedef typename Node<T>::node_ref_t node_ref_t;
        const node_ref_t& getRoot() const;
        void insert(T);

    private:
        void insert(node_ref_t &, T);
        node_ref_t m_root;
    };

    template <typename T>
    typename Node<T>::node_ref_t makeNode(T);

}

#endif //TREE_TREE_H
