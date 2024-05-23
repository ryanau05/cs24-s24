#include "List.h"
#include <iostream>

// List Member Functions

list::node::node(const std::string& key_, int data_){
    key = key_;
    data = data_;
    next = nullptr;
    prev = nullptr;
}

list::list(){
    head = nullptr;
    tail = nullptr;
    count = 0;
}

list::~list(){
    node* curr = head;
    while (curr != nullptr){
        node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    count = 0;
}

void list::insert(node* add){
    if (head == nullptr){
        head = add;
    }
    else {
        node* curr = tail;
        curr->next = add;
        add->prev = curr;
    }
    tail = add;
    count++;
}

list::node* list::find(const std::string& key_) const{
    node* curr = head;
    while (curr != nullptr && curr->key != key_) {
        curr = curr->next;
    }
    return curr;
}

void list::remove(std::string key_){
    node* curr = find(key_);
    if (head->next == nullptr){                     // if removing only node in list
        head = nullptr;
        delete curr;
    }
    else if (head == curr){                         // if removing head
        head = curr->next;
        head->prev = nullptr;
        delete curr;
    }
    else if (curr->next == nullptr){                // if removing tail
        (curr->prev)->next = nullptr;
        delete curr;
    }
    else {                                          // removing body node
        (curr->prev)->next = curr->next;
        (curr->next)->prev = curr->prev;
        delete curr;
    }
    count--;
}
