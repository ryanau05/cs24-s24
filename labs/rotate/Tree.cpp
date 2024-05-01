#include "Tree.h"
#include <iostream>
// Tree Function Implementations
Tree::Tree(){
    root = nullptr;
}

Tree::~Tree(){
    delete root;
}

void Tree::clear(){
    clearAll(root);
    nodeCount = 0;
}

void Tree::clearAll(Node* node){
    if (node == nullptr){
        return;
    }
    clearAll(node->left);
    clearAll(node->right);
    
    delete node;
}

bool Tree::isLeaf(Node* node){
    if (node->left == nullptr && node->right == nullptr){
        return true;
    }
    return false;
}

void Tree::adjustWeight(Node* node, bool increase){
    while (node != root){
        if (increase){
            node->weight += 1;
        }
        else {
            node->weight -= 1;
        }
        node = node->parent;
    }
    
    if (increase){
        root->weight += 1;
    }
    else {
        root->weight -= 1;
    }
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
    while (true){
        if (s <= curr->data){
            if (curr->left != nullptr){
                curr = curr->left;
            }
            else {
                curr->left = add;
                add->parent = curr;
                nodeCount += 1;
                adjustWeight(curr, true);
                //rebalance(curr->parent);
                return;
            }
        }
        else if (s > curr->data){
            if (curr->right != nullptr){
                curr = curr->right;
            }
            else {
                curr->right = add;
                add->parent = curr;
                nodeCount += 1;
                adjustWeight(curr, true);
                //rebalance(curr->parent);
                return;
            }
        }
    }
}

void Tree::print() const{
    std::cout << print_all(root) << std::endl;
}

std::string Tree::print_all(const Node* node) const{
    if (node == nullptr) {
        return "-";
    }

    // std::cout << "(";
    // print_all(node->left);
    // std::cout << " " << node->data << " ";
    // print_all(node->right);
    // std::cout << ")";
    if (node->left == nullptr && node->right == nullptr) {
        return node->data;
    }
    return "(" + print_all(node->left) + " " + node->data + " " + print_all(node->right) + ")";
}



size_t Tree::find(const std::string& s) const{
    return 2;
}

std::string Tree::lookup(size_t index) const{
    return "STUB";
}

void Tree::remove(size_t index){
    return;
}