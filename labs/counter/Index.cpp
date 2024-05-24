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
    list::node* node_to_remove = find_(key_);
    if (node_to_remove == nullptr) {
        return;
    }

    list::node* curr = table[hashValue].head;
    if (curr == nullptr) {
        return;
    }

    // Find the node just before the node to be removed
    while (curr->hashNext != nullptr && (curr->hashNext)->key != key_) {
        curr = curr->hashNext;
    }

    // If we reach here, curr->hashNext is the node to be removed
    list::node* temp = curr->hashNext;
    if (temp == nullptr) {
        return;
    }

    // Remove temp from the hash chain
    if (temp->hashNext == nullptr) {
        curr->hashNext = nullptr;
    } else {
        curr->hashNext = temp->hashNext;
    }

    // Remove temp from the doubly linked list
    if (temp == table[hashValue].head) {  // If temp is head
        if (temp->next == nullptr) {
            table[hashValue].head = nullptr;
        } else {
            table[hashValue].head = temp->next;
        }
    } else {
        if (temp->next == nullptr) {  // If temp is tail
            if (temp->prev != nullptr) {
                (temp->prev)->next = nullptr;
            }
            table[hashValue].tail = temp->prev;
        } else {
            if (temp->prev != nullptr) {
                (temp->prev)->next = temp->next;
            }
            if (temp->next != nullptr) {
                (temp->next)->prev = temp->prev;
            }
        }
    }

    delete temp;
}