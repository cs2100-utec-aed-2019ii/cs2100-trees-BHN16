#ifndef TREES_BINARYTREE_H
#define TREES_BINARYTREE_H
#include "Node.h"
#include <iostream>
template<class T>
class BinaryTree{
private:
    typedef Node<T> Node;
    void In_order(Node* a) {
        if(a) {
            In_order(a->left);
            std::cout << a->key << " -> ";
            In_order(a->right);
        }
    }

    void Pre_order(Node* a) {
        if(a) {
            std::cout << a->key << " -> ";
            Pre_order(a->left);
            Pre_order(a->right);
        }
    }

    void Post_order(Node* a) {
        if(a) {
            Post_order(a->left);
            Post_order(a->right);
            std::cout << a->key << " -> ";
        }
    }

    unsigned int Height(Node* a) {
        if(!a) {
            return -1;
        }
        else {
            unsigned int L = Height(a->left);
            unsigned int R = Height(a->right);
            unsigned int max = (L>R)? L : R;
            return 1+max;
        }
    }

    Node* get_search(T val, Node* a) {
        if(a == nullptr || val == a->key) {
            return a;
        }
        else if(val < a->key){
            return get_search(val,a->left);
        }
        else {
            return get_search(val,a->right);
        }
    }

    Node* min_right(Node* ptr) {
        while(ptr->left->left) {
            ptr = ptr->left;
        }
        return ptr;
    }

    Node* max_left(Node* ptr) {
        while(ptr->right->right) {
            ptr = ptr->right;
        }
        return ptr;
    }

    void t_delete(Node* t) {
        if(!t->right && t->left) {
            t_delete(t->left);
        }
        else if(!t->left && t->right) {
            t_delete(t->right);
        }
        else if(t->right && t->left) {
            t_delete(t->left);
            t_delete(t->right);
        }
        else {
            delete t;
            t = nullptr;
        }
    }

    void a_delete(Node* h) {
        Node* temp = nullptr;
        if(!h->right && h->left) {
            temp = max_left(h->left);
            h->key = temp->right->key;
            delete temp->right;
            temp->right = nullptr;
        }
        else if(!h->left && h->right){
            temp = min_right(h->right);
            h->key = temp->left->key;
            delete temp->left;
            temp->left = nullptr;
        }
        else if(h->left && h->right) {
            temp = min_right(h->right);
            h->key = temp->left->key;
            delete temp->left;
            temp->left = nullptr;
        }
        else {
            delete h;
        }
    }

public:
    Node* root;

    BinaryTree() {
        this->root = nullptr;
    }

    BinaryTree(T val) {
        this->root = new Node(val);
    }
    void InsertNode(T val) {
        Node** In = &root;
        while(*In) {
            if((*In)->key > val) {
                In = &((*In)->left);
            }
            else if((*In)->key < val) {
                In = &((*In)->right);
            }
        }
        *In = new Node(val);
    }

    void print_Inorder() {
        std::cout << "In order : ";
        In_order(this->root);
        std::cout << std::endl;
    }

    void print_Preorder() {
        std::cout << "Pre order : ";
        Pre_order(this->root);
        std::cout << std::endl;
    }

    void print_Postorder() {
        std::cout << "Post order : ";
        Post_order(this->root);
        std::cout << std::endl;
    }

    unsigned int get_Height() {
       return Height(this->root);
    }

    bool Search(T val) {
        Node* temp = get_search(val, this->root);
        return temp;
    }

    void DeleteNode(T data) {
        Node* it = get_search(data,this->root);
        if(it) {
            a_delete(it);
        }
        else {
            std::cout << "No se encuentra el valor.\n";
        }
    }

    void Delete_Tree() {
        t_delete(this->root);
        this->root = nullptr;
    }

};
#endif
