// Index.cpp
#include "Index.h"
#include <functional>

Index::Index() {
    table = new list[capacity];
}

Index::~Index() {
    delete[] table;
}

size_t Index::hash(const std::string& key_) const {
    std::hash<std::string> hasher;
    return hasher(key_) % capacity;
}

void Index::insert_(const std::string& key_, list::node* nodePtr) {
    size_t hashValue = hash(key_);
    table[hashValue].insert(nodePtr);
}

list::node* Index::find_(const std::string& key_) const {
    size_t hashValue = hash(key_);
    return table[hashValue].find(key_);
}

void Index::remove_(const std::string& key_) {
    size_t hashValue = hash(key_);
    table[hashValue].remove(key_);
}
