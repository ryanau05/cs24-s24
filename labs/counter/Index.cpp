#include "Index.h"
#include <functional>

// Index Member Functions

Index::Index() {
    table = new list[capacity];
}

// Index::~Index() {
//     for (size_t i = 0; i < capacity; i++){
//         table[i].head = nullptr;
//     }
//     delete[] table;
// }

Index::~Index() {
    for (size_t i = 0; i < capacity; i++) {
        // Clean up the linked lists in the hash table
        list::node* current = table[i].head;
        while (current != nullptr) {
            list::node* next = current->hashNext;
            delete current;
            current = next;
        }
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
        nodePtr->hashPrev = curr;
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

// void Index::remove_(const std::string& key_) {
//     size_t hashValue = hash(key_);
//     list::node* rm = find_(key_);
//     if (rm == nullptr) {
//         return;                                     // node not in list
//     }

//     if (table[hashValue].head == rm && table[hashValue].tail == rm){        // if only node in chain
//         table[hashValue].head = nullptr;
//         table[hashValue].tail = nullptr;
//     }
//     else if (table[hashValue].head == rm){               // if node is head
//         table[hashValue].head = rm->hashNext;
//         (rm->hashNext)->hashPrev = nullptr;
//     }
//     else if (table[hashValue].tail == rm){          // if node is tail
//         table[hashValue].tail = rm->hashPrev;
//         (rm->hashPrev)->hashNext = nullptr;
//     }
// }
void Index::remove_(const std::string& key_) {
    size_t hashValue = hash(key_);
    list::node* rm = find_(key_);
    if (rm == nullptr) {
        return;  // node not in list
    }

    if (table[hashValue].head == rm && table[hashValue].tail == rm) { // if only node in chain
        table[hashValue].head = nullptr;
        table[hashValue].tail = nullptr;
    } else if (table[hashValue].head == rm) { // if node is head
        table[hashValue].head = rm->hashNext;
        if (rm->hashNext) {
            rm->hashNext->hashPrev = nullptr;
        }
    } else if (table[hashValue].tail == rm) { // if node is tail
        table[hashValue].tail = rm->hashPrev;
        if (rm->hashPrev) {
            rm->hashPrev->hashNext = nullptr;
        }
    } else { // if node is in the middle
        if (rm->hashPrev) {
            rm->hashPrev->hashNext = rm->hashNext;
        }
        if (rm->hashNext) {
            rm->hashNext->hashPrev = rm->hashPrev;
        }
    }

    // Important: Unlink the node completely
    rm->hashNext = nullptr;
    rm->hashPrev = nullptr;
}