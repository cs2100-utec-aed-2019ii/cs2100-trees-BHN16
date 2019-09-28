#ifndef TREES_NODE_H
#define TREES_NODE_H
template<class T>
class Node{
private:
    T key;
public:
    Node<T>* left;
    Node<T>* right;
    Node<T>* next;
    Node(T key) {
        this->key = key;
        this->right = nullptr;
        this->left = nullptr;
        this->next = nullptr;
    }
    template<class Y>
    friend class BinaryTree;
};
#endif
