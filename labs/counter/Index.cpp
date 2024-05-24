#include "Index.h"
#include <functional>

// Index Member Functions

Index::Index() {
    table = new list[capacity];
}

Index::~Index() {
    for (size_t i = 0; i < capacity; i++){
        table[i].head = nullptr;
    }
    delete[] table;
}

size_t Index::hash(const std::string& key_) const {
    std::hash<std::string> hasher;
    return hasher(key_) % capacity;
}

void Index::insert_(const std::string& key_, list::node* nodePtr) {
    size_t hashValue = hash(key_);
    if (table[hashValue].head == nullptr){
        table[hashValue].head = nodePtr;
    }
    else {
        list::node* curr = table[hashValue].tail;
        curr->hashNext = nodePtr;
    }
    table[hashValue].tail = nodePtr;
}

list::node* Index::find_(const std::string& key_) const {
    size_t hashValue = hash(key_);
    if (table[hashValue].head == nullptr){
        return nullptr;
    }
    list::node* curr = table[hashValue].head;
     while (curr != nullptr && curr->key != key_){
        curr = curr->hashNext;
    }

    return curr;
}

void Index::remove_(const std::string& key_) {
    size_t hashValue = hash(key_);
    if (find_(key_) == nullptr){
        return;
    }
    list::node* curr = table[hashValue].head;
    // if (curr->key == key_){
    //     if (curr->hashNext != nullptr){
    //         table[hashValue].head = curr->hashNext;
    //     }
    //     else {
    //         table[hashValue].head = nullptr;
    //     }
    //     (curr->prev)->next = curr->next;
    //     (curr->next)->prev = curr->prev;
    //     delete curr;
    // }
    while ((curr->hashNext)->key != key_){
        curr = curr->hashNext;
    }

    list::node* temp = curr->hashNext;
    if (temp->hashNext == nullptr){
        curr->hashNext = nullptr;
    }
    else {
        curr->hashNext = temp->hashNext;
    }

    if (temp == table[hashValue].head){             // if temp is head
        if (temp->next == nullptr){
            table[hashValue].head = nullptr;
        }
        else {
            table[hashValue].head = temp->next;
        }
    }
    else {
        if (temp->next == nullptr){                 // if temp is tail
            (temp->prev)->next = nullptr;
            table[hashValue].tail = temp->prev;
        }
        else {
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
        }
    }



    // while ((curr->hashNext)->key != key_){
    //     curr = curr->hashNext;
    // }

    // list::node* temp = curr->hashNext;
    // curr->hashNext = temp->hashNext;
    // curr->next = temp->next;
    // (temp->next)->prev = curr;
    delete temp;
}