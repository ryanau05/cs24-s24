#include "Tree.h"
#include <iostream>
// Tree Function Implementations
Tree::Tree(){
    root = new Node;
    root = nullptr;
}

Tree::~Tree(){
    delete root;
}

void Tree::clearAll(Node* node){
    if (node == nullptr){
        return;
    }
    clearAll(node->left);
    clearAll(node->right);
    
    delete node;
}

void Tree::clear(){
    clearAll(root);
    nodeCount = 0;
}

size_t Tree::count() const{
    return nodeCount;
}

bool Tree::contains(const std::string& s) const{
    if (root == nullptr){
        return false;
    }

    Node* curr = root;
    while (s != curr->data){
        if ((s < curr->data && curr->left == nullptr) || (s > curr->data && curr->right == nullptr)){
            return false;
        }
        else if (s < curr->data){
            curr = curr->left;
        }
        else if (s > curr->data){
            curr = curr->right;
        }

    }
    return true;
}

void Tree::insert(const std::string& s){
    Node* add = new Node;
    add->data = s;
    
    if (root == nullptr){
        root = add;
        nodeCount += 1;
        return;
    }

    Node* curr = root;
    while (curr->left != nullptr && curr->right != nullptr){
        if (s <= curr->data){
            curr = curr->left;
        }
        else if (s > curr->data){
            curr = curr->right;
        }
    }
    if (s <= curr->data){
        curr->left = add;
    }
    else {
        curr->right = add;
    }

    add->parent = curr; 
    nodeCount += 1;

    while (curr != root){
        curr->weight += 1;
        curr = curr->parent;
    }
    root->weight += 1;
}

void Tree::print() const{
    print_all(root);
    std::cout << std::endl;
}

void Tree::print_all(const Node* node) const{
    if (node == nullptr) {
        std::cout << "-";
    } 
    else {
        std::cout << "(";
        print_all(node->left);
        std::cout << " " << node->data << " ";
        print_all(node->right);
        std::cout << ")";
    }
}