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
        return;  // Node not found, nothing to remove
    }

    // Remove node from the hash chain
    list::node* curr = table[hashValue].head;
    if (curr == node_to_remove) {
        table[hashValue].head = node_to_remove->hashNext;
    } else {
        while (curr != nullptr && curr->hashNext != node_to_remove) {
            curr = curr->hashNext;
        }
        if (curr != nullptr) {
            curr->hashNext = node_to_remove->hashNext;
        }
    }

    // Remove node from the doubly linked list
    if (node_to_remove->prev != nullptr) {
        node_to_remove->prev->next = node_to_remove->next;
    } else {
        // Node to remove is the head of the linked list
        table[hashValue].head = node_to_remove->next;
    }

    if (node_to_remove->next != nullptr) {
        node_to_remove->next->prev = node_to_remove->prev;
    } else {
        // Node to remove is the tail of the linked list
        table[hashValue].tail = node_to_remove->prev;
    }

    delete node_to_remove;
}