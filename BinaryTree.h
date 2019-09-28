#ifndef TREES_BINARYTREE_H
#define TREES_BINARYTREE_H
#include "Node.h"
#include <iostream>
#include <vector>
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

    Node** get_search(T val, Node** a) {
        if((*a) == nullptr || val == (*a)->key) {
            return a;
        }
        else if(val < (*a)->key){
            return get_search(val,&(*a)->left);
        }
        else {
            return get_search(val,&(*a)->right);
        }
    }

    Node** minimum(Node** ptr) {
        while((*ptr)->left) {
            *ptr = (*ptr)->left;
        }
        return ptr;
    }

    Node** maximum(Node** ptr) {
        while((*ptr)->right) {
            *ptr = (*ptr)->right;
        }
        return ptr;
    }

    void t_delete(Node* t) {
        if(!t->right && t->left) {
            t_delete(t->left);
        }
        if(!t->left && t->right) {
            t_delete(t->right);
        }
        if(t->right && t->left) {
            t_delete(t->left);
            t_delete(t->right);
        }
        delete t;
        t = nullptr;
    }

    void n_delete(Node** h) {
        if((*h)->right && !(*h)->left) {
            Node* temp = *h;
            h = &(*h)->right;
            std::cout << temp->key << " Right\n";
            delete temp;
        }
        if((*h)->left && !(*h)->right) {
            Node* temp = *h;
            h = &(*h)->left;
            std::cout << temp->key << " Left\n";
            delete temp;
        }
        if((*h)->right && (*h)->left) {
            Node** temp = minimum(&(*h)->right);
            (*h)->key = (*temp)->key;
            std::cout << (*temp)->key << " Right & Left\n";
            n_delete(temp);
            std::cout << (*h)->key  << std::endl;
        }
        else {
            std::cout << "Delete hecho.\n";
            delete *h;
            *h = nullptr;
        }
    }

    std::vector<T> get_ancestors(Node* ptr, T val) {
        std::vector<T> var;
        while(ptr) {
            if(ptr->key == val) {
                return var;
            }
            if(ptr->key < val) {
                var.push_back(ptr->key);
                ptr = ptr->right;
            }
            if(ptr->key > val) {
                var.push_back(ptr->key);
                ptr = ptr->left;
            }
        }
        return var;
    }

    Node* next_same_level(Node* ptr) {

    }

    void identical(Node* j, std::vector<T>* k) {
        if(j) {
            k->push_back(j->key);
            identical(j->left, k);
            identical(j->right, k);
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
        Node** temp = get_search(val, &this->root);
        return *temp;
    }

    void DeleteNode(T data) {
        Node** it = get_search(data,&this->root);
        if(it) {
            n_delete(it);
        }
        else {
            std::cout << "No se encuentra el valor.\n";
        }
    }

    void Delete_Tree() {
        t_delete(this->root);
        this->root = nullptr;
    }

    void ancestors(T val) {
        std::vector<T> g = get_ancestors(this->root,val);
        std::cout << "Ancestors : ";
        for(int i = 0; i < g.size(); i++) {
            std::cout << g[i] << " ";
        }
        std::cout << std::endl;
    }

    

    bool check_identical(Node* r) {
        std::vector<T>* h = new std::vector<T>;
        std::vector<T>* g = new std::vector<T>;
        identical(this->root, h);
        identical(r,g);
        if((*h) == (*g)) {
            return true;
        }
        else {
            return false;
        }
    }
};
#endif
#ifndef TREES_BINARYTREE_H
#define TREES_BINARYTREE_H
#include "Node.h"
#include <iostream>
#include <vector>
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

    Node** get_search(T val, Node** a) {
        if((*a) == nullptr || val == (*a)->key) {
            return a;
        }
        else if(val < (*a)->key){
            return get_search(val,&(*a)->left);
        }
        else {
            return get_search(val,&(*a)->right);
        }
    }

    Node** minimum(Node** ptr) {
        while((*ptr)->left) {
            *ptr = (*ptr)->left;
        }
        return ptr;
    }

    Node** maximum(Node** ptr) {
        while((*ptr)->right) {
            *ptr = (*ptr)->right;
        }
        return ptr;
    }

    void t_delete(Node* t) {
        if(!t->right && t->left) {
            t_delete(t->left);
        }
        if(!t->left && t->right) {
            t_delete(t->right);
        }
        if(t->right && t->left) {
            t_delete(t->left);
            t_delete(t->right);
        }
        delete t;
        t = nullptr;
    }

    void n_delete(Node** h) {
        if((*h)->right && !(*h)->left) {
            Node* temp = *h;
            h = &(*h)->right;
            std::cout << temp->key << " Right\n";
            delete temp;
        }
        if((*h)->left && !(*h)->right) {
            Node* temp = *h;
            h = &(*h)->left;
            std::cout << temp->key << " Left\n";
            delete temp;
        }
        if((*h)->right && (*h)->left) {
            Node** temp = minimum(&(*h)->right);
            (*h)->key = (*temp)->key;
            std::cout << (*temp)->key << " Right & Left\n";
            n_delete(temp);
            std::cout << (*h)->key  << std::endl;
        }
        else {
            std::cout << "Delete hecho.\n";
            delete *h;
            *h = nullptr;
        }
    }

    std::vector<T> get_ancestors(Node* ptr, T val) {
        std::vector<T> var;
        while(ptr) {
            if(ptr->key == val) {
                return var;
            }
            if(ptr->key < val) {
                var.push_back(ptr->key);
                ptr = ptr->right;
            }
            if(ptr->key > val) {
                var.push_back(ptr->key);
                ptr = ptr->left;
            }
        }
        return var;
    }

    Node* next_same_level(Node* ptr) {

    }

    void identical(Node* j, std::vector<T>* k) {
        if(j) {
            k->push_back(j->key);
            identical(j->left, k);
            identical(j->right, k);
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
        Node** temp = get_search(val, &this->root);
        return *temp;
    }

    void DeleteNode(T data) {
        Node** it = get_search(data,&this->root);
        if(it) {
            n_delete(it);
        }
        else {
            std::cout << "No se encuentra el valor.\n";
        }
    }

    void Delete_Tree() {
        t_delete(this->root);
        this->root = nullptr;
    }

    void ancestors(T val) {
        std::vector<T> g = get_ancestors(this->root,val);
        std::cout << "Ancestors : ";
        for(int i = 0; i < g.size(); i++) {
            std::cout << g[i] << " ";
        }
        std::cout << std::endl;
    }

    

    bool check_identical(Node* r) {
        std::vector<T>* h = new std::vector<T>;
        std::vector<T>* g = new std::vector<T>;
        identical(this->root, h);
        identical(r,g);
        if((*h) == (*g)) {
            return true;
        }
        else {
            return false;
        }
    }
};
#endif
