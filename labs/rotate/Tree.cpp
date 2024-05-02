#include "Tree.h"
#include <iostream>
#include <stdexcept>
// Tree Function Implementations
Tree::Tree(){
    root = nullptr;
    nodeCount = 0;
}

Tree::~Tree(){
    clear();
}

int Tree::calcImbalance(Node* node){
    int left, right, imbalance;
    if (node->left == nullptr){
        left = 0;
    }
    else {
        left = (node->left)->weight;
    }
    if (node->right == nullptr){
        right = 0;
    }
    else {
        right = (node->right)->weight;
    }

    imbalance = left - right;
    if (imbalance < 0){
        imbalance *= -1;
    }
    
    return imbalance;
}

void Tree::promote(Node* promote){
    if (calcImbalance(promote) < 3){
        return;
    }


}

void Tree::clear(){
    clearAll(root);
    nodeCount = 0;
    root = nullptr;
}

void Tree::clearAll(Node* node){
    if (node == nullptr){
        return;
    }
    clearAll(node->left);
    clearAll(node->right);
    
    delete node;
}

bool Tree::isLeaf(Node* node) const{
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

    if (node->left == nullptr && node->right == nullptr) {
        return node->data;
    }

    return "(" + print_all(node->left) + " " + node->data +  " " + print_all(node->right) + ")";
}

std::string Tree::lookup(size_t index) const{
    return "STUB";
}

void Tree::remove(size_t index){
    if (nodeCount == 1){
        delete root;
        root = nullptr;
        nodeCount -= 1;
        return;
    }
    if (index > nodeCount){
        throw std::out_of_range();

    }

    return;
}

int index1 = 0;

int Tree::findHelp(Node* node, const std::string& s) const{
    if (root == nullptr) {
        return -1;
    }

    int left_index = findHelp(root->left, s);
    if (left_index != -1) {
        return left_index;
    }

    index1++;
    if (root->data == s) {
        return index1;
    }

    return findHelp(root->right, s);
}


size_t Tree::find(const std::string& s) const{
    if (!contains(s)){
        return SIZE_MAX;
    }

    return findHelp(root, s);
}